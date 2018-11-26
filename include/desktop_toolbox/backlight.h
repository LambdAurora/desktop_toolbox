/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of desktop_toolbox.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#ifndef DESKTOP_TOOLBOX_BACKLIGHT_H
#define DESKTOP_TOOLBOX_BACKLIGHT_H

#include "desktop_toolbox_exports.h"
#include <lambdacommon/types.h>

namespace desktop_toolbox
{
	namespace backlight
	{
		/*!
		 * Checks whether the computer has backlight or not.
		 * @return True if the computer has backlight, else false.
		 */ 
		extern bool DESKTOP_TOOLBOX_API has_backlight();

		/*!
		 * Gets the maximum brightness on the specified device.
		 *
		 * Notes: 
		 *  - On Linux device will be always 0 since there is only one ACPI kernel module that manages the backlight.
		 *
		 * @param device The targeted device, default is 0.
		 */ 
		extern uint32_t DESKTOP_TOOLBOX_API get_max_brightness(uint32_t device = 0);

		/*!
		 * Gets the current brightness on the specified device.
		 * @param device The targeted device, default is 0.
		 */ 
		extern uint32_t DESKTOP_TOOLBOX_API get_brightness(uint32_t device = 0);

		/*!
		 * Sets the brightness on the specified device.
		 * @param device The targeted device, default is 0.
		 * @param brightness The brightness value.
		 */ 
		extern void DESKTOP_TOOLBOX_API set_brightness(uint32_t device, uint32_t brightness);
	}
}

#endif // DESKTOP_TOOLBOX_BACKLIGHT_H
