#ifndef _SERVO_CONSTANTS
#define _SERVO_CONSTANTS

#define CLK_DIV 249.93
#define TOP 10000

typedef struct Servo {
    int slice;
    int pin;
} Servo;

Servo *servo_init(int);
void servo_move_to_angle(Servo *servo, float angle);
int angle_to_ticks(float);

#endif


