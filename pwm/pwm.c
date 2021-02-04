#include<stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

void main() {
    const int SERVO_PIN = 25;
    const int PWM_HIGH = 50;

    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    pwm_set_wrap(slice_num, PWM_HIGH);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_wrap(&config, PWM_HIGH);
    pwm_config_set_phase_correct(&config, true);
    pwm_init(slice_num, &config, false);
    int i = 1;
    int dir = 1;
    while(1) {
        if(i > PWM_HIGH || i <= 0) {
            dir *= -1;
        }
        pwm_set_chan_level(slice_num, pwm_gpio_to_channel(SERVO_PIN), i);
        pwm_set_enabled(slice_num, true);
        sleep_ms(16);
        i += dir;
    }
}