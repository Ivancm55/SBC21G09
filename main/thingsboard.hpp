#include "constantes.h"

/* Conexion con ThingsBoard */
char thingsboardServer[] = "thingsboard.cloud";
WiFiClient espClient;
ThingsBoard tb(espClient);

/*
 * Funciones Thingsboard
 */

/* Reconectar con el servidor de ThingsBoard */
void reconnectTB() {
  // Loop until we're reconnected
  while (!tb.connected()) {
    Serial.print("Connecting to ThingsBoard node ...");
    // Attempt to connect (clientId, username, password)
    if ( tb.connect(thingsboardServer, TOKEN) ) {
      Serial.println( "[DONE]" );
    } else {
      Serial.print( "[FAILED]" );
      Serial.println( " : retrying in 5 seconds" );
      // Wait 5 seconds before retrying
      delay( 5000 );
    }
  }
}

/* Subir los datos a ThingsBoard */
void subirDatosThingsBoard(double temp, double hum, double luz, double presion, int turbidez, boolean nivelAgua) {
  tb.sendTelemetryFloat("Temperatura Ambiente", float(temp));
  tb.sendTelemetryFloat("Humedad Ambiente", float(hum));
  tb.sendTelemetryFloat("Luminosidad", float(luz));
  tb.sendTelemetryFloat("Presion", float(presion));
  if(turbidez > 4550) {
    tb.sendTelemetryFloat("Turbidez", 0.0);
  }
  else {
    tb.sendTelemetryFloat("Turbidez", float(turbidez));
  }
  tb.sendTelemetryBool("Nivel Agua", nivelAgua);
}
