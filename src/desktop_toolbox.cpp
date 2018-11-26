/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of desktop_toolbox.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#include "../include/desktop_toolbox/desktop_toolbox.h"

namespace desktop_toolbox
{
	std::string DESKTOP_TOOLBOX_API get_version()
	{
		return std::to_string(DESKTOP_TOOLBOX_VERSION_MAJOR) + '.' + std::to_string(DESKTOP_TOOLBOX_VERSION_MINOR) + '.' +
					std::to_string(DESKTOP_TOOLBOX_VERSION_PATCH);
	}
}
