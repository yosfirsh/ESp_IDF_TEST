#include "buzzer.h"
#include "driver/gpio.h"

void initBuzzer(int gpio_pin){
    // Konfigurasi GPIO sebagai output
    gpio_config_t io_conf = {
        .pin_bit_mask = 1ULL << gpio_pin, // Pilih pin LED
        .mode = GPIO_MODE_OUTPUT,        // Set mode sebagai output
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .intr_type = GPIO_INTR_DISABLE   // Tidak ada interrupt
    };
    gpio_config(&io_conf);
}

void onBuzzer(int gpio_pin){
    // Mengaktifkan LED
    gpio_set_level(gpio_pin, 1);
}

void offBuzzer(int gpio_pin){
    // Menonaktifkan LED
    gpio_set_level(gpio_pin, 0);
}