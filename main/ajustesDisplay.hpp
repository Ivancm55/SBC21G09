#include "constantes.h"

/* Comunicacion con el display */
Genie genie;

/*
 *  Funciones indicadores display
 */

/* Dia */
void ajustar_Temperatura_Display_Dia(double temp) {
  genie.WriteStr(1, temp, 2);

  if(temp >= TEMP_DIA_OPTIMA_INF && temp <= TEMP_DIA_OPTIMA_SUP) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 1, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 2, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 3, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 4, true);
  }
  else if(temp >= TEMP_DIA_BAJA && temp <= TEMP_DIA_ALTA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 1, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 2, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 3, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 4, false);
  }
  else if(temp >= TEMP_DIA_MINIMA && temp <= TEMP_DIA_MAXIMA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 1, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 2, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 3, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 4, false);
  }
  else {
    genie.WriteObject(GENIE_OBJ_USER_LED, 1, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 2, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 3, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 4, false);
  }
}

void ajustar_Humedad_Display_Dia(double hum) {
  genie.WriteStr(5, hum, 2);

  if(hum >= HUM_DIA_OPTIMA_INF && hum <= HUM_DIA_OPTIMA_SUP) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 5, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 6, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 7, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 8, true);
  }
  else if(hum >= HUM_DIA_BAJA && hum <= HUM_DIA_ALTA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 5, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 6, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 7, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 8, false);
  }
  else if(hum >= HUM_DIA_MINIMA && hum <= HUM_DIA_MAXIMA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 5, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 6, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 7, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 8, false);
  }
  else {
    genie.WriteObject(GENIE_OBJ_USER_LED, 5, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 6, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 7, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 8, false);
  }
}

void ajustar_Luz_Display_Dia(double luz) {
  genie.WriteStr(3, luz, 2);

  if(luz >= LUZ_DIA_BAJA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 9, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 10, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 11, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 12, true);
  }
  else if(luz >= LUZ_DIA_MUY_BAJA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 9, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 10, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 11, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 12, false);
  }
  else if(luz >= LUZ_DIA_MALA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 9, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 10, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 11, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 12, false);
  }
  else {
    genie.WriteObject(GENIE_OBJ_USER_LED, 9, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 10, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 11, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 12, false);
  }
}

/* Noche */
void ajustar_Temperatura_Display_Noche(double temp) {
  genie.WriteStr(1, temp, 2);

  if(temp >= TEMP_NOCHE_OPTIMA_INF && temp <= TEMP_NOCHE_OPTIMA_SUP) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 1, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 2, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 3, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 4, true);
  }
  else if(temp >= TEMP_NOCHE_BAJA && temp <= TEMP_NOCHE_ALTA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 1, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 2, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 3, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 4, false);
  }
  else if(temp >= TEMP_NOCHE_MINIMA && temp <= TEMP_NOCHE_MAXIMA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 1, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 2, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 3, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 4, false);
  }
  else {
    genie.WriteObject(GENIE_OBJ_USER_LED, 1, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 2, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 3, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 4, false);
  }
}

void ajustar_Humedad_Display_Noche(double hum) {
  genie.WriteStr(5, hum, 2);

  if(hum >= HUM_NOCHE_OPTIMA_INF && hum <= HUM_NOCHE_OPTIMA_SUP) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 5, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 6, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 7, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 8, true);
  }
  else if(hum >= HUM_NOCHE_BAJA && hum <= HUM_NOCHE_ALTA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 5, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 6, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 7, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 8, false);
  }
  else if(hum >= HUM_NOCHE_MINIMA && hum <= HUM_NOCHE_MAXIMA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 5, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 6, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 7, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 8, false);
  }
  else {
    genie.WriteObject(GENIE_OBJ_USER_LED, 5, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 6, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 7, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 8, false);
  }
}

void ajustar_Luz_Display_Noche(double luz) {
  genie.WriteStr(3, luz, 2);

  if(luz >= LUZ_NOCHE_BAJA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 9, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 10, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 11, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 12, true);
  }
  else if(luz >= LUZ_NOCHE_MUY_BAJA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 9, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 10, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 11, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 12, false);
  }
  else if(luz >= LUZ_NOCHE_MALA) {
    genie.WriteObject(GENIE_OBJ_USER_LED, 9, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 10, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 11, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 12, false);
  }
  else {
    genie.WriteObject(GENIE_OBJ_USER_LED, 9, true);
    genie.WriteObject(GENIE_OBJ_USER_LED, 10, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 11, false);
    genie.WriteObject(GENIE_OBJ_USER_LED, 12, false);
  }
}
