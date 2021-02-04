include(pico_sdk_import.cmake)

project(servo)

pico_sdk_init()

add_executable(servo servo.c)

target_link_libraries(servo pico_stdlib hardware_pwm)

pico_add_extra_outputs(servo)