/*
 * Copyright © 2018 LambdAurora <aurora42lambda@gmail.com>
 *
 * This file is part of desktop_toolbox.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#include "../../include/desktop_toolbox/desktop_toolbox.h"
#include "../../include/desktop_toolbox/backlight.h"
#include <lambdacommon/system/system.h>
#include <lambdacommon/lstring.h>
#include <iostream>

namespace terminal = lambdacommon::terminal;

int main(int argc, char **argv)
{
	terminal::setup();
	terminal::set_title("Backlight");
	std::cout << terminal::GREEN << "Desktop toolbox v" << desktop_toolbox::get_version() << std::endl;
	std::cout << "Backlight is supported? " << lambdacommon::lstring::to_string(desktop_toolbox::backlight::has_backlight()) << std::endl;
	return EXIT_SUCCESS;
}
