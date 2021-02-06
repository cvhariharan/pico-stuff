#include<stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "include/servo.h"

void main() {
    const int SERVO_PIN = 4;
    const int SWITCH_PIN = 6;

    Servo *servo = servo_init(SERVO_PIN);

    gpio_init(SWITCH_PIN);
    gpio_set_dir(SWITCH_PIN, false);
    gpio_pull_up(SWITCH_PIN);

    servo_move_to_angle(servo, 0);
    sleep_ms(500);

    while(1) {
        sleep_ms(500);
        int val = gpio_get(SWITCH_PIN);
        if(val) {
            continue;
        }
        servo_move_to_angle(servo, 70);
        sleep_ms(1000);
        servo_move_to_angle(servo, 0);
        sleep_ms(200);
    }
}


