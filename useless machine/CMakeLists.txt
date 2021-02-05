include(pico_sdk_import.cmake)

project(useless_machine)

pico_sdk_init()

add_executable(useless_machine box.c include/servo.c)

target_link_libraries(useless_machine pico_stdlib hardware_pwm)

pico_add_extra_outputs(useless_machine)