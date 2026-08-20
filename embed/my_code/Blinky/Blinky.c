/**
 * Vinnie K. (vkumar82@asu.edu)
 */


 #include "pico/stdlib.h"

 #define LED_PIN 25

 int main(){

    //init the gpio pin
    gpio_init(LED_PIN);

    //configure the pin as output
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    while(true){
        gpio_put(LED_PIN, 1);
        busy_wait_ms(250);
        gpio_put(LED_PIN, 0);
        busy_wait_ms(250);
    }

 }
