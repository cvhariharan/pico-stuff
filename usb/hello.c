#include<stdio.h>
#include "pico/stdlib.h"
void main() {
    stdio_init_all();
    while(1) {
        printf("Hello World from Pico\n");
        sleep_ms(1000);
    }
}