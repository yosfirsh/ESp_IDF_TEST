#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "buzzer/buzzer.h"
#include "buzzerTask/buzzerTask.h"

// Pin GPIO yang digunakan untuk mengontrol buzzer
#define buzzer_gpio_pin 33

void app_main(void){

    // =========================================================
    // Inisialisasi modul buzzer
    // ---------------------------------------------------------
    // initBuzzer() adalah fungsi untuk mengatur pin buzzer
    // sebagai output dan menyiapkan perangkat agar siap digunakan.
    // Parameter:
    //   buzzer_gpio_pin → nomor GPIO tempat buzzer terhubung.
    // =========================================================
    initBuzzer(buzzer_gpio_pin);

    
    // =========================================================
    // Menjalankan task buzzer
    // ---------------------------------------------------------
    // buzzerTask() akan membuat task FreeRTOS yang mengatur
    // cara kerja buzzer (misalnya bunyi berulang, pola beep, dsb.)
    // Task ini berjalan secara paralel (multitasking).
    //
    // Parameter:
    //   buzzer_gpio_pin → digunakan oleh task untuk mengontrol buzzer.
    // =========================================================
    buzzerTask(buzzer_gpio_pin);


    // =========================================================
    // Menunggu beberapa waktu
    // ---------------------------------------------------------
    // vTaskDelay() digunakan untuk membuat delay non-blocking.
    // Program ditunda selama 5 detik.
    //
    // 5000 / portTICK_PERIOD_MS → mengubah delay (ms) ke tick RTOS.
    // =========================================================
    vTaskDelay(5000 / portTICK_PERIOD_MS);


    // =========================================================
    // Menghentikan task buzzer
    // ---------------------------------------------------------
    // stopBuzzerTask() akan menghentikan task yang sebelumnya dibuat.
    // Setelah fungsi ini dipanggil, buzzer tidak lagi dimainkan.
    // =========================================================
    stopBuzzerTask();
}
