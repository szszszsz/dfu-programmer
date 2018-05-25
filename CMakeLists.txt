cmake_minimum_required(VERSION 3.9)
project(dfu_programmer C)

set(CMAKE_C_STANDARD 11)

set(SRC
        src/arguments.c
        src/arguments.h
        src/atmel.c
        src/atmel.h
        src/commands.c
        src/commands.h
        src/dfu-bool.h
        src/dfu-device.h
        src/dfu.c
        src/dfu.h
        src/intel_hex.c
        src/intel_hex.h
        src/stm32.c
        src/stm32.h
        src/util.c
        src/util.h)
#        windows/usb.h

add_executable(dfu_programmer
        src/main.c
        )
add_executable(libtest
        libtest.c
        )

add_library(dfup ${SRC}
        src/lib_implementation.c src/lib_implementation.h
        )

#target_compile_definitions(dfu_programmer PUBLIC HAVE_LIBUSB_1_0)
target_compile_definitions(dfu_programmer PUBLIC HAVE_CONFIG_H)
target_compile_definitions(dfup PUBLIC HAVE_CONFIG_H)
include_directories(/usr/include/libusb-1.0)
target_link_libraries(dfup usb-1.0)
target_link_libraries(libtest dfup)
target_link_libraries(dfu_programmer dfup)

