include(pico_sdk_import.cmake)

project(pwm)

pico_sdk_init()

add_executable(pwm pwm.c)

target_link_libraries(pwm pico_stdlib hardware_pwm)

pico_add_extra_outputs(pwm)