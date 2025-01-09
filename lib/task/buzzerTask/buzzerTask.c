#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "buzzer/buzzer.h"
#include "buzzerTask.h"

static TaskHandle_t buzzerTaskHandle = NULL; // Handle untuk task

// Fungsi task untuk kontrol buzzer
void buzzer_task(void *param) {
    int gpio_pin = *(int *)param; // Mengambil pin dari parameter
    while (1) {
        onBuzzer(gpio_pin); // Menyalakan buzzer
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Tunggu 1 detik
        offBuzzer(gpio_pin); // Mematikan buzzer
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Tunggu 1 detik
    }
}

void buzzerTask(int gpio_pin) {
    // Membuat task untuk kontrol buzzer
    if (buzzerTaskHandle == NULL) { // Pastikan task belum berjalan
        xTaskCreate(
            buzzer_task,            // Fungsi task
            "Buzzer Task",          // Nama task
            2048,                   // Ukuran stack
            (void *)&gpio_pin,      // Parameter untuk task
            5,                      // Prioritas task
            &buzzerTaskHandle       // Simpan handle task
        );
    } else {
        printf("Buzzer task already running!\n");
    }
}

void stopBuzzerTask() {
    if (buzzerTaskHandle != NULL) {
        vTaskDelete(buzzerTaskHandle); // Hapus task
        buzzerTaskHandle = NULL;       // Reset handle
        printf("Buzzer task stopped.\n");
    } else {
        printf("Buzzer task is not running.\n");
    }
}