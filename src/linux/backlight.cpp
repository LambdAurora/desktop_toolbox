/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of desktop_toolbox.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#include "../../include/desktop_toolbox/backlight.h"
#include <lambdacommon/system/fs/filesystem.h>
#include <lambdacommon/maths.h>
#include <fstream>

#define BACKLIGHT_ACPI "/sys/class/backlight/"
#define BACKLIGHT_ACPI_INTEL "intel_backlight"
#define BACKLIGHT_ACPI_ATI "acpi_video0"

namespace desktop_toolbox
{
	namespace backlight
	{
		std::string backlight_path = "";

		bool DESKTOP_TOOLBOX_API has_backlight()
		{
			lambdacommon::fs::FilePath file{std::string(BACKLIGHT_ACPI) + std::string(BACKLIGHT_ACPI_ATI) + "/"};
			if (!backlight_path.empty())
				return true;
			if (file.exists() && file.is_directory())
			{
				backlight_path = file.to_string();
				return true;
			}
			else
			{
				file = {std::string(BACKLIGHT_ACPI) + std::string(BACKLIGHT_ACPI_INTEL) + "/"};
				if (file.exists() && file.is_directory())
				{
					backlight_path = file.to_string();
					return true;
				}
			}
			return false;
		}

		uint32_t DESKTOP_TOOLBOX_API get_max_brightness(uint32_t device)
		{
			if (!has_backlight())
				return 0;
			std::ifstream max_brightness_filestream;
			max_brightness_filestream.open(backlight_path + "max_brightness", std::ios::in);
			uint32_t max_brightness = 0;
			if (max_brightness_filestream.is_open())
			{
				max_brightness_filestream >> max_brightness;
				max_brightness_filestream.close();
			}
			return max_brightness;
		}

		uint32_t DESKTOP_TOOLBOX_API get_brightness(uint32_t device)
		{
			if (!has_backlight())
				return 0;
			std::ifstream brightness_filestream;
			brightness_filestream.open(backlight_path + "brightness", std::ios::in);
			uint32_t brightness = 0;
			if (brightness_filestream.is_open())
			{
				brightness_filestream >> brightness;
				brightness_filestream.close();
			}
			return brightness;
		}

		void DESKTOP_TOOLBOX_API set_brightness(uint32_t device, uint32_t brightness)
		{
			if (!has_backlight())
				return;
			brightness = lambdacommon::maths::clamp(brightness, static_cast<uint32_t>(0), get_max_brightness(device));
			std::ofstream brightness_filestream;
			brightness_filestream.open(backlight_path + "brightness", std::ios::out);
			if (brightness_filestream.is_open())
			{
				brightness_filestream << std::to_string(brightness);
				brightness_filestream.close();
			}
		}
	}
}
