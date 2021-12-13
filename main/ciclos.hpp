#include "constantes.h"

Adafruit_NeoPixel ledRGB = Adafruit_NeoPixel(1, PIN_RGB, NEO_GRB + NEO_KHZ800);

String informacion = "";

/*
 * Funcion Ciclo Dia
 */
void cicloDia(float temp, float hum) {
  if(temp >= TEMP_DIA_OPTIMA_INF && temp <= TEMP_DIA_OPTIMA_SUP) {
      if(hum >= HUM_DIA_OPTIMA_INF && hum <= HUM_DIA_OPTIMA_SUP) {
        ledRGB.setPixelColor(0, ledRGB.Color(0, 255, 0));
        ledRGB.show();
        Serial.println("Ambiente perfecto");
        informacion = "rgb(0,255,0);font-size:150%'> Ambiente perfecto" ;
        genie.WriteStr(0, "Ambiente perfecto");
      }
      else if(hum >= HUM_DIA_BAJA && hum <= HUM_DIA_ALTA) {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 233, 0));
        ledRGB.show();
        Serial.println("Ambiente ligeramente mejorable");
        informacion = "rgb(255,233,0);font-size:150%'> Ambiente ligeramente mejorable" ;
        genie.WriteStr(0, "Ambiente ligeramente mejorable");
      }
      else if(hum >= HUM_DIA_MINIMA && hum <= HUM_DIA_MAXIMA) {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 127, 0));
        ledRGB.show();
        Serial.println("Ambiente muy mejorable");
        informacion = "rgb(255,127,0);font-size:150%'> Ambiente muy mejorable" ;
        genie.WriteStr(0, "Ambiente muy mejorable");
      }
      else {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 0, 0));
        ledRGB.show();
        Serial.println("Ambiente malo");
        informacion = "rgb(255,0,0);font-size:150%'> Ambiente malo";
        genie.WriteStr(0, "Ambiente malo");
      }
    }
    else if(temp >= TEMP_DIA_BAJA && temp <= TEMP_DIA_ALTA){
      if(hum >= HUM_DIA_BAJA && hum <= HUM_DIA_ALTA) {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 233, 0));
        ledRGB.show();
        Serial.println("Ambiente ligeramente mejorable");
        informacion = "rgb(255,233,0);font-size:150%'> Ambiente ligeramente mejorable" ;
        genie.WriteStr(0, "Ambiente ligeramente mejorable");
      }
      else if(hum >= HUM_DIA_MINIMA && hum <= HUM_DIA_MAXIMA) {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 127, 0));
        ledRGB.show();
        Serial.println("Ambiente muy mejorable");
        informacion = "rgb(255,127,0);font-size:150%'> Ambiente muy mejorable" ;
        genie.WriteStr(0, "Ambiente muy mejorable");
      }
      else {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 0, 0));
        ledRGB.show();
        Serial.println("Ambiente malo");
        informacion = "rgb(255,0,0);font-size:150%'> Ambiente malo";
        genie.WriteStr(0, "Ambiente malo");
      }
    }
    else if(temp >= TEMP_DIA_MINIMA && temp <= TEMP_DIA_MAXIMA){
      if(hum >= HUM_DIA_MINIMA && hum <= HUM_DIA_MAXIMA) {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 127, 0));
        ledRGB.show();
        Serial.println("Ambiente muy mejorable");
        informacion = "rgb(255,127,0);font-size:150%'> Ambiente muy mejorable" ;
        genie.WriteStr(0, "Ambiente muy mejorable");
      }
      else {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 0, 0));
        ledRGB.show();
        Serial.println("Ambiente malo");
        informacion = "rgb(255,0,0);font-size:150%'> Ambiente malo";
        genie.WriteStr(0, "Ambiente malo");
      }
    }
    else {
      ledRGB.setPixelColor(0, ledRGB.Color(255, 0, 0));
      ledRGB.show();
      Serial.println("Ambiente malo");
      informacion = "rgb(255,0,0);font-size:150%'> Ambiente malo";
      genie.WriteStr(0, "Ambiente malo");
    }
}

/*
 * Funcion Ciclo Noche
 */
void cicloNoche(float temp, float hum) {
  if(temp >= TEMP_NOCHE_OPTIMA_INF && temp <= TEMP_NOCHE_OPTIMA_SUP) {
      if(hum >= HUM_NOCHE_OPTIMA_INF && hum <= HUM_NOCHE_OPTIMA_SUP) {
        ledRGB.setPixelColor(0, ledRGB.Color(0, 255, 0));
        ledRGB.show();
        Serial.println("Ambiente perfecto");
        informacion = "rgb(0,255,0);font-size:150%'> Ambiente perfecto";
        genie.WriteStr(0, "Ambiente perfecto");
      }
      else if(hum >= HUM_NOCHE_BAJA && hum <= HUM_NOCHE_ALTA) {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 233, 0));
        ledRGB.show();
        Serial.println("Ambiente ligeramente mejorable");
        informacion = "rgb(255,233,0);font-size:150%'> Ambiente ligeramente mejorable";
        genie.WriteStr(0, "Ambiente ligeramente mejorable");
      }
      else if(hum >= HUM_NOCHE_MINIMA && hum <= HUM_NOCHE_MAXIMA) {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 127, 0));
        ledRGB.show();
        Serial.println("Ambiente muy mejorable");
        informacion = "rgb(255,127,0);font-size:150%'> Ambiente muy mejorable";
        genie.WriteStr(0, "Ambiente muy mejorable");
      }
      else {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 0, 0));
        ledRGB.show();
        Serial.println("Ambiente malo");
        informacion = "rgb(255,0,0);font-size:150%'> Ambiente malo";
        genie.WriteStr(0, "Ambiente malo");
      }
    }
    else if(temp >= TEMP_NOCHE_BAJA && temp <= TEMP_NOCHE_ALTA){
      if(hum >= HUM_NOCHE_BAJA && hum <= HUM_NOCHE_ALTA) {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 233, 0));
        ledRGB.show();
        Serial.println("Ambiente ligeramente mejorable");
        informacion = "rgb(255,233,0);font-size:150%'> Ambiente ligeramente mejorable";
        genie.WriteStr(0, "Ambiente ligeramente mejorable");
      }
      else if(hum >= HUM_NOCHE_MINIMA && hum <= HUM_NOCHE_MAXIMA) {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 127, 0));
        ledRGB.show();
        Serial.println("Ambiente muy mejorable");
        informacion = "rgb(255,127,0);font-size:150%'> Ambiente muy mejorable";
        genie.WriteStr(0, "Ambiente muy mejorable");
      }
      else {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 0, 0));
        ledRGB.show();
        Serial.println("Ambiente malo");
        informacion = "rgb(255,0,0);font-size:150%'> Ambiente malo";
        genie.WriteStr(0, "Ambiente malo");
      }
    }
    else if(temp >= TEMP_NOCHE_MINIMA && temp <= TEMP_NOCHE_MAXIMA){
      if(hum >= HUM_NOCHE_MINIMA && hum <= HUM_NOCHE_MAXIMA) {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 127, 0));
        ledRGB.show();
        Serial.println("Ambiente muy mejorable");
        informacion = "rgb(255,127,0);font-size:150%'> Ambiente muy mejorable";
        genie.WriteStr(0, "Ambiente muy mejorable");
      }
      else {
        ledRGB.setPixelColor(0, ledRGB.Color(255, 0, 0));
        ledRGB.show();
        Serial.println("Ambiente malo");
        informacion = "rgb(255,0,0);font-size:150%'> Ambiente malo";
        genie.WriteStr(0, "Ambiente malo");
      }
    }
    else {
      ledRGB.setPixelColor(0, ledRGB.Color(255, 0, 0));
      ledRGB.show();
      Serial.println("Ambiente malo");
      informacion = "rgb(255,0,0);font-size:150%'> Ambiente malo";
      genie.WriteStr(0, "Ambiente malo");
    }
}
