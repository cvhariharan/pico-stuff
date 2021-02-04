/*
This example runs the servo in an anti-clockwise direction in steps of 36 degrees.
The values for the clk divider, pwm top ticks and timings are all based on the 
sg90 servo. You may need to adjust the duty cycle depending on your servo
but this example should work with most servos.

-----------------
Servo    |  Pico
-----------------
Data     |  GPIO4
VCC      |  VBUS
GND      |  GND
-----------------
*/

#include<stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#ifndef _SERVO_CONSTANTS
#define _SERVO_CONSTANTS

#define CLK_DIV 249.93
#define TOP 10000

#endif

void main() {
    const int SERVO_PIN = 4;

    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    pwm_set_wrap(slice_num, TOP);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_wrap(&config, TOP);
    pwm_config_set_clkdiv(&config, CLK_DIV);
    pwm_init(slice_num, &config, false);

    // pwm_freq = 125000000÷(10000×1×(249+15÷16)) = 50.012Hz
    // time_period = 1/50.012 = 0.02 seconds
    // time_per_tick = (0.02*1000)/10000 = 0.002 ms
    // duty_cycle_level (ticks) for 1ms = 1/0.002 = 500

    while(1) {
        //  ~1ms
        pwm_set_chan_level(slice_num, pwm_gpio_to_channel(SERVO_PIN), 500);
        pwm_set_enabled(slice_num, true);
        sleep_ms(1000);
        // ~1.5ms
        pwm_set_chan_level(slice_num, pwm_gpio_to_channel(SERVO_PIN), 750);
        pwm_set_enabled(slice_num, true);
        sleep_ms(1000);
        // ~2ms
        pwm_set_chan_level(slice_num, pwm_gpio_to_channel(SERVO_PIN), 1000);
        pwm_set_enabled(slice_num, true);
        sleep_ms(1000);
        // ~2.5ms
        pwm_set_chan_level(slice_num, pwm_gpio_to_channel(SERVO_PIN), 1250);
        pwm_set_enabled(slice_num, true);
        sleep_ms(1000);
        // ~3ms
        pwm_set_chan_level(slice_num, pwm_gpio_to_channel(SERVO_PIN), 1500);
        pwm_set_enabled(slice_num, true);
        sleep_ms(1000);
    }
}