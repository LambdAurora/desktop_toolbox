/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of desktop_toolbox.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#ifndef DESKTOP_TOOLBOX_LIBRARY_H
#define DESKTOP_TOOLBOX_LIBRARY_H

#include <string>
#include "desktop_toolbox_exports.h"

#define DESKTOP_TOOLBOX_VERSION_MAJOR 0
#define DESKTOP_TOOLBOX_VERSION_MINOR 0
#define DESKTOP_TOOLBOX_VERSION_PATCH 0

namespace desktop_toolbox
{
	extern std::string DESKTOP_TOOLBOX_API get_version();
}

#endif // DESKTOP_TOOLBOX_LIBRARY_H
