#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Добре було би, якби всі ці піни інтерапт підтримували
uint8_t button1 = 1; // example
uint8_t button2 = 2; // example
uint8_t button3 = 3; // example
uint8_t button4 = 4; // example
uint8_t encoderPin = 5; // example

char* ssid = "WIFI_NAME";
char* password = "WIFI_PASSWORD";

#endif // CONFIG_H