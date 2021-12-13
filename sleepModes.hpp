#include "constantes.h"

/*
 * RTC GPIO HOLD Funciones
 */

/* Funcion para habilitar el mantener el valor en los pines del display y del led */
void rtc_hold_en_pines() {
  esp_err_t rtc_gpio_hold_en1(GPIO_NUM_14);    /* Led */
  esp_err_t rtc_gpio_hold_en2(GPIO_NUM_23);    /* Bomba */
}

/* Funcion para deshabilitar el mantener el valor en los pines del display y del led */
void rtc_hold_dis_pines() {
  esp_err_t rtc_gpio_hold_dis1(GPIO_NUM_14);   /* Led */
  esp_err_t rtc_gpio_hold_dis2(GPIO_NUM_23);   /* Bomba */
}


/*
 * Sleep Modes ESP32
 */

/* Funcion deep sleep para el ESP32 */
void goToDeepSleep() {
  Serial.println("Procesador a dormir (Deep Sleep) ...");

  esp_sleep_enable_timer_wakeup(SLEEP_TIME*1000000);            /* 10 Segundos (para la demostracion) */
  esp_deep_sleep_start();
}

/* Funcion light sleep para el ESP32 */
void goToLightSleep() {
  Serial.println("Procesador a dormir (Light Sleep) ...");

  esp_sleep_enable_timer_wakeup(SLEEP_TIME*1000000);            /* 10 Segundos (para la demostracion) */
  esp_light_sleep_start();
} 
