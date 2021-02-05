#include<stdio.h>

#include "pico/stdlib.h"
#include "hardware/pwm.h"

#include "servo.h"


Servo *servo_init(int pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    
    uint slice_num = pwm_gpio_to_slice_num(pin);

    pwm_set_wrap(slice_num, TOP);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_wrap(&config, TOP);
    pwm_config_set_clkdiv(&config, CLK_DIV);
    pwm_init(slice_num, &config, false);

    Servo *servo = (Servo *) malloc(sizeof(Servo));
    servo->slice = slice_num;
    servo->pin = pin;
    return servo;
}

void servo_move_to_angle(Servo *servo, float angle) {
    pwm_set_chan_level(servo->slice, pwm_gpio_to_channel(servo->pin), angle_to_ticks(angle));
    pwm_set_enabled(servo->slice, true);
    sleep_ms(100);
}

int angle_to_ticks(float angle) {
    const float ticks_per_deg = 5.55;
    return (500 + angle * 5.55);
}