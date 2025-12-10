---
# 📘 **Buzzer Task ESP32 (ESP-IDF)**

Proyek ini menunjukkan cara menggunakan **ESP32 + ESP-IDF** untuk mengontrol buzzer menggunakan **FreeRTOS Task**. Program memisahkan logika buzzer dalam sebuah task sehingga buzzer dapat dijalankan dan dihentikan secara fleksibel tanpa mengganggu task lainnya.
---

## 📂 **Struktur Proyek**

```
/main
 ├── buzzer/
 │    ├── buzzer.c
 │    ├── buzzer.h
 │
 ├── buzzerTask/
 │    ├── buzzerTask.c
 │    ├── buzzerTask.h
 │
 ├── main.c
```

---

## 🚀 **Fitur Utama**

- Inisialisasi buzzer melalui driver terpisah
- Task FreeRTOS untuk mengontrol pola bunyi buzzer
- Kemampuan untuk memulai dan menghentikan task buzzer kapan pun
- Program utama tetap bersih dan modular

---

## 🛠️ **Hardware yang Dibutuhkan**

- ESP32 DevKit (atau varian apa pun)
- Buzzer aktif atau pasif
- Kabel jumper
- Buzzer terhubung ke GPIO (default: GPIO 33)

---

## 🔌 **Koneksi Hardware**

| ESP32 Pin | Buzzer    |
| --------- | --------- |
| GPIO 33   | IN/Signal |
| GND       | GND       |
| 3.3V      | VCC       |

Jika menggunakan buzzer aktif → langsung berbunyi ketika HIGH
Jika buzzer pasif → suara mengikuti PWM atau toggling pin

---

## 📄 **Cara Kerja Program**

1. Modul buzzer diinisialisasi dengan `initBuzzer()`.
2. Task buzzer dijalankan menggunakan `buzzerTask()`.
3. Task tersebut berjalan paralel dan mengontrol pola bunyi buzzer.
4. Program menunggu 5 detik.
5. Task dihentikan dengan `stopBuzzerTask()`.

---

## 🧩 **Kode Utama (main.c)**

```c
#define buzzer_gpio_pin 33

void app_main(void){
    initBuzzer(buzzer_gpio_pin); // Inisialisasi buzzer
    buzzerTask(buzzer_gpio_pin); // Mulai task buzzer

    vTaskDelay(5000 / portTICK_PERIOD_MS); // Tunggu 5 detik

    stopBuzzerTask(); // Hentikan task buzzer
}
```

---

## 📦 **Build & Flash**

Pastikan sudah berada di direktori proyek:

```sh
idf.py build
idf.py flash
idf.py monitor
```

---

## 🧠 **Penjelasan FreeRTOS Task**

- Task buzzer berjalan sendiri (non-blocking).
- `vTaskDelay()` digunakan agar tidak menghambat task lain.
- `stopBuzzerTask()` menghentikan task menggunakan mekanisme task handle.

---

## 🗂️ **File Penjelasan**

### **buzzer.h / buzzer.c**

Berisi driver dasar untuk:

- inisialisasi GPIO
- fungsi on/off buzzer
- abstraction layer agar mudah digunakan oleh task

### **buzzerTask.h / buzzerTask.c**

Berisi:

- pembuatan task
- pola bunyi buzzer
- mekanisme stop task

---
