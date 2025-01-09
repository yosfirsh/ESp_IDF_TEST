#ifndef BUZZER_H
#define BUZZER_H

//Inisialisasi GPIO untuk Buzzer
void initBuzzer(int gpio_pin);

//Mengaktifkan Buzzer
void onBuzzer(int gpio_pin);

//Menonaktifkan Buzzer
void offBuzzer(int gpio_pin);

#endif