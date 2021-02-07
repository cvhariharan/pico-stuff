include(pico_sdk_import.cmake)

project(usb)

pico_sdk_init()

add_executable(usb hello.c)

target_link_libraries(usb pico_stdlib)

pico_enable_stdio_usb(usb 1)
pico_enable_stdio_uart(usb 0)

pico_add_extra_outputs(usb)