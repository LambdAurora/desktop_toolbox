cmake_minimum_required(VERSION 3.6)
project(desktop_toolbox)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(GenerateExportHeader)
include(utils/CompileUtility)
include(utils/InstallUtility)

set(CMAKE_CXX_STANDARD 14)

# Options
option(DESKTOP_TOOLBOX_INSTALL "Generate installation target" ON)

generate_flags(DESKTOP_TOOLBOX_COMPILE_FLAGS "native" 2 true)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}${DESKTOP_TOOLBOX_COMPILE_FLAGS}")

# Finds the library lambdacommon.
find_package(lambdacommon REQUIRED)

include_directories(${LAMBDACOMMON_INCLUDE_DIRS})

# All files:
# There is the C++ header files.
set(HEADER_FILES include/desktop_toolbox/desktop_toolbox.h include/desktop_toolbox/backlight.h)
# There is the C++ source files.
set(SOURCE_FILES src/desktop_toolbox.cpp)

if (UNIX AND NOT APPLE)
	set(SOURCE_FILES ${SOURCE_FILES} src/linux/backlight.cpp)
endif ()

# Build the shared library.
add_library(desktoptoolbox SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(desktoptoolbox AperLambda::lambdacommon)
# Generate the export header and include it.
GENERATE_EXPORT_HEADER(desktoptoolbox
	BASE_NAME desktop_toolbox
	EXPORT_MACRO_NAME DESKTOP_TOOLBOX_API
	EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/desktop_toolbox_exports.h
	STATIC_DEFINE DESKTOP_TOOLBOX_SHARED_EXPORTS_BUILT_AS_STATIC)
target_include_directories(desktoptoolbox PUBLIC ${CMAKE_BINARY_DIR}/exports)

add_executable(dtbacklight src/apps/dtbacklight.cpp)
target_link_libraries(dtbacklight desktoptoolbox AperLambda::lambdacommon)

# Install if the option is on.
if (DESKTOP_TOOLBOX_INSTALL)
	foreach (LOOP_HEADER ${HEADER_FILES})
		get_filename_component(HEADER_PARENT_DIR ${LOOP_HEADER} DIRECTORY)
		install(FILES ${LOOP_HEADER} DESTINATION ${HEADER_PARENT_DIR})
	endforeach ()
	install(FILES ${CMAKE_BINARY_DIR}/exports/desktop_toolbox_exports.h DESTINATION include/desktop_toolbox)
	install(TARGETS desktoptoolbox dtbacklight
			RUNTIME DESTINATION bin
			LIBRARY DESTINATION lib
			ARCHIVE DESTINATION lib)
	
	# Uninstall target
	setup_uninstall_target()
endif ()
