/* Pines empleados para los sensores y actuadores */
#define PIN_RGB 14
#define PIN_NIVEL_AGUA 21
#define PIN_BOMBA 23
#define PIN_TURBIDITY 35
#define PIN_RELE 33
#define PIN_RX_DISPLAY 25
#define PIN_TX_DISPLAY 26
#define RESETLINE 27  /* Pin RES para el display */

/* Direccion para la comunicacion I2C del RTC */
#define RTC_I2C_ADDRESS 0x68

/* Valores para los parametros del cultivo (en este caso lechuga) */
/* Valores para el dia */
#define TEMP_DIA_MINIMA -6
#define TEMP_DIA_BAJA 8
#define TEMP_DIA_OPTIMA_INF 14
#define TEMP_DIA_OPTIMA_SUP 18
#define TEMP_DIA_ALTA 24
#define TEMP_DIA_MAXIMA 30

#define HUM_DIA_MINIMA 30
#define HUM_DIA_BAJA 40
#define HUM_DIA_OPTIMA_INF 55
#define HUM_DIA_OPTIMA_SUP 80
#define HUM_DIA_ALTA 85
#define HUM_DIA_MAXIMA 90

#define LUZ_DIA_MALA 500
#define LUZ_DIA_MUY_BAJA 1000
#define LUZ_DIA_BAJA 2000

/* Valores para la noche */
#define TEMP_NOCHE_MINIMA -6
#define TEMP_NOCHE_BAJA 0
#define TEMP_NOCHE_OPTIMA_INF 5
#define TEMP_NOCHE_OPTIMA_SUP 8
#define TEMP_NOCHE_ALTA 15
#define TEMP_NOCHE_MAXIMA 30

#define HUM_NOCHE_MINIMA 30
#define HUM_NOCHE_BAJA 40
#define HUM_NOCHE_OPTIMA_INF 55
#define HUM_NOCHE_OPTIMA_SUP 80
#define HUM_NOCHE_ALTA 85
#define HUM_NOCHE_MAXIMA 90

#define LUZ_NOCHE_MALA 250
#define LUZ_NOCHE_MUY_BAJA 500
#define LUZ_NOCHE_BAJA 1000

/* Valor en segundos para el tiempo que se mantiene dormido el procesador */
#define SLEEP_TIME 10     /* Tiempo bajo para la demostracion */

/* Token para enviar datos a ThingsBoard */
#define TOKEN "ESP32_Hidroponicos"
