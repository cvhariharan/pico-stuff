#include<stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "include/servo.h"

void main() {
    const int SERVO_PIN = 4;

    Servo *servo = servo_init(SERVO_PIN);
    while(1) {
        servo_move_to_angle(servo, 90);
        sleep_ms(1000);
        servo_move_to_angle(servo, 180);
        sleep_ms(1000);
        servo_move_to_angle(servo, 30);
        sleep_ms(1000);
        servo_move_to_angle(servo, 50);
        sleep_ms(1000);
        servo_move_to_angle(servo, 10);
        sleep_ms(1000);
        servo_move_to_angle(servo, 110);
        sleep_ms(1000);
    }
}


