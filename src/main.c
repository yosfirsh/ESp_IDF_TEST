#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "buzzer/buzzer.h"
#include "buzzerTask/buzzerTask.h"

#define buzzer_gpio_pin 33

void app_main(void){
    initBuzzer(buzzer_gpio_pin); // Inisialisasi buzzer
    
    // Jalankan task buzzer
    buzzerTask(buzzer_gpio_pin);

    // Tunggu beberapa detik sebelum menghentikan task
    vTaskDelay(5000 / portTICK_PERIOD_MS); // Tunggu 5 detik
    stopBuzzerTask(); // Hentikan task buzzer
}