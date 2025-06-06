cmake_minimum_required(VERSION 3.16)
project(ubuntu-frame)
include(FindPkgConfig)

set(CMAKE_CXX_STANDARD 20)
pkg_check_modules(MIRAL miral REQUIRED)
pkg_check_modules(WAYLAND_CLIENT REQUIRED wayland-client)
pkg_check_modules(APPARMOR libapparmor REQUIRED)

add_executable(frame
    frame_main.cpp
    frame_authorization.cpp frame_authorization.h
    frame_window_manager.cpp frame_window_manager.h
    egwallpaper.cpp egwallpaper.h
    egfullscreenclient.cpp egfullscreenclient.h
)

target_compile_definitions(frame PRIVATE MIR_LOG_COMPONENT="frame")

target_include_directories(frame PUBLIC SYSTEM ${MIRAL_INCLUDE_DIRS})
target_link_libraries(frame ${MIRAL_LDFLAGS} ${WAYLAND_CLIENT_LIBRARIES} ${APPARMOR_LIBRARIES})

install(PROGRAMS ${CMAKE_BINARY_DIR}/frame
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)
