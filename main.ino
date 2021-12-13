#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <Update.h>
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_NeoPixel.h>
#include <BH1750.h>
#include <genieArduino.h>
#include <SoftwareSerial.h>
#include <cjson.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <ThingsBoard.h>

#include "ajustesDisplay.hpp"
#include "ciclos.hpp"
#include "constantes.h"
#include "rtc.hpp"
#include "sleepModes.hpp"
#include "thingsboard.hpp"


/* Comunicacion con el display */
SoftwareSerial SerialDisplay(PIN_RX_DISPLAY, PIN_TX_DISPLAY);

/* Iniciar sensores */
Adafruit_BME280 bme;
BH1750 sensorLuz(0x5C);

/* Conexion a la red WiFi */
const char* host = "SBC21G09";
const char* ssid = "SBC";
const char* password = "sbc$2020";

/* Iniciar servidor web */
WebServer server(80);

/*
 * Login Page
 */

const char* loginIndex =
 "<!doctype html>"
"<html lang='en'>"
"<head>"
"<meta charset='utf-8'>"
"<meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'>"
"<title>Home</title>"
"<style type='text/css'>"
 "body {"
    "font-family: 'Montserrat', sans-serif;"
    "text-rendering : optimizeLegibility;"
    "-webkit-font-smoothing : antialiased;"
  "}"
  "#login-bg.container-fluid {"
    "padding: 0;"
    "height: 100%;"
    "position: absolute;"
    "background-color: #CAF0D3;"
    
  "}"
  "#login{"
    "padding-top: 10%;"
    "text-align: center;"
    "text-transform: uppercase;"
  "}"
  ".login {"
    "width: 100%;"
    "height: 500px;"
    "background-color:#CAF0D3;"
    "padding: 15px;"
    "padding-top: 30px;"
  "}"
  ".login h1 {"
    "margin-top: 30px;"
    "font-weight: bold;"
    "font-size: 60px;"
    "letter-spacing: 3px;"
  "}"
  ".login form {"
    "max-width: 420px;"
    "margin: 30px auto;"
  "}"
  ".login .btn {"
    "border-radius: 50px;"
    "text-transform: uppercase;"
    "font-weight: bold;"
    "letter-spacing: 2px;"
    "font-size: 20px;"
    "padding: 14px;"
    "background-color: #00B72E;"
  "}"
  ".form-group input {"
    "font-size: 20px;"
    "font-weight: lighter;"
    "border: none;"
    "background-color: #F0F0F0;"
    "color: #465347!important;"
    "padding: 26px 30px;"
    "border-radius: 50px;"
    "transition : 0.2s;"
    "margin-bottom: 5px;"
  "}"
  "#bgcolor{"
    "background-color: #CAF0D3;"
  "}"
  "@media(max-width: 500px) { "
    "#login {"
      "padding-top: 50px;"
    "}"
  "}"
"</style>"
"</head>"
"<body id='bgcolor'>"
"<div class='container' id='login'>"
  "<div class='row justify-content-center'>"
  "<div class='col-lg-8'>"
    "<div class='login'>"
    "<h1>Login</h1>"
        "<form>"
        "<div class='form-group'>"
          "<input type='text' class='form-control' id='exampleInputEmail1' name='usr' placeholder='Usuario'>"  
        "</div>"
        "<div class='form-group'>"
          "<input type='password' class='form-control' id='exampleInputPassword1' name='pwd' placeholder='Password'>"
        "</div>" 
        "<br>"
        "<button class='btn btn-lg btn-block btn-success' onclick='myFunction()'>Sign in</button>"
        "</form>"
      "<script>"
      "function myFunction() {"
        "var usr = document.getElementById('exampleInputEmail1');"
        "var pwd = document.getElementById('exampleInputPassword1');"
        "if (usr.value == 'admin' && pwd.value == 'admin'){"
            "window.open('/serverIndex');"
            "}"
          "else if (usr.value == 'alumno' && pwd.value == 'alumno'){"
          "window.open('/datos');"
            "}else{alert('Error Password or Username');}"
      
        "document.getElementById('demo').innerHTML = 'Hello World';"
      "}"
      "</script>"   
  "</div>"
  "</div>"
"</div>"
"</body>"
"</html>";

/*
 * Server Index Page
 */

const char* serverIndex =
"<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>"
"<body style='background-color:#CAF0D3;'>" 
"<form style='margin-left:30%;' method='POST' action='#' enctype='multipart/form-data' id='upload_form'></br>"
   "<input style='font-size: 20px;' type='file' name='update'></br></br>"
        "<input style='margin-left:20%; font-size: 20px; background-color: #04AA6D; color: #ffffff;' type='submit' value='Update'>"
    "</form>"
 "<div style='margin-left: 35%; font-size: 20px;' id='prg'>progress: 0%</div>"
 "<script>"
  "$('form').submit(function(e){"
  "e.preventDefault();"
  "var form = $('#upload_form')[0];"
  "var data = new FormData(form);"
  " $.ajax({"
  "url: '/update',"
  "type: 'POST',"
  "data: data,"
  "contentType: false,"
  "processData:false,"
  "xhr: function() {"
  "var xhr = new window.XMLHttpRequest();"
  "xhr.upload.addEventListener('progress', function(evt) {"
  "if (evt.lengthComputable) {"
  "var per = evt.loaded / evt.total;"
  "$('#prg').html('progress: ' + Math.round(per*100) + '%');"
  "}"
  "}, false);"
  "return xhr;"
  "},"
  "success:function(d, s) {"
  "console.log('success!')"
 "},"
 "error: function (a, b, c) {"
 "}"
 "});"
 "});"
 "</script>"
 "</body>";

/*
 * Pagina para mostrar los datos
 */

String datos0 =
"<!DOCTYPE html>"
"<html>"
"<head>"
"<title>Home</title>"
"<link href='http://fonts.useso.com/css?family=Oxygen:400,300,700' rel='stylesheet' type='text/css'>"
"<link href='http://fonts.useso.com/css?family=Open+Sans:400,600,700' rel='stylesheet' type='text/css'>"
"<link href='http://fonts.useso.com/css?family=Raleway:100,200' rel='stylesheet' type='text/css'>"
"<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>"
"<style>"
    
  "ol,ul{list-style:none;padding:0;margin:0;}"
  ".clear{clear:both;}"
  "img{max-width:100%;}"
    "body {"
  "background-color: #CAF0D3;"
  "background-repeat: no-repeat;"
  "background-attachment: fixed;"
  "background-position: center;"
  "background-size: cover;"
  "-webkit-background-size: cover;"
  "-moz-background-size: cover;"
  "-o-background-size: cover;"
  "font-family: 'Open Sans', sans-serif;"
  "text-align: center;"
"}"
"body a {"
  "transition: 0.5s all;"
  "-webkit-transition: 0.5s all;"
  "-moz-transition :0.5s all;"
  "-o-transition: 0.5s all;"
  "-ms-transition: 0.5s all;"
  "text-decoration: none;"
    "}"
    ".container {"
        "width: 65%;"
        "margin: 50px auto;"
        "background-color: rgba(0, 0, 0, 0.255);background-image :url('https://image.freepik.com/free-vector/hand-painted-watercolor-flowers-background_79603-1498.jpg'); background-size : cover;"
        "}"
        ".city {"
            "width: 60%;"
            "float: right;"
            "background-repeat: no-repeat;"
            "background-size: cover;"
            "-webkit-background-size: cover;"
            "-moz-background-size: cover;"
            "-o-background-size: cover;"
            "min-height: 500px;"
            "position: relative;"
"}"
    ".forecast {"
  "width: 40%;"
  "float: left;"
    "}"
    ".today-weather ul li {"
  "width: 154%;"
  "margin: 0 auto;"
  "line-height: 39px;"
  "border-width: thin;"
  "color: #EEE;"
  "font-weight: 600;"
  "text-align: left;"
  "padding-left: 20px;"
    "}"
"</style>"
"</head>"
"<body>"
    "<div class='container'>"
        "<div class='city'>"
            "<div class='title'>"
        "</div>"
                "</div>"
                "<div class='forecast'>"
                    "<div class='forecast-icon'>"
                        "<img>"
                        "</div>"
                        "<div class='today-weather'>"
                        "<ul style = 'margin-top:30%; margin-left:15%;'>";
String datos1 =
"<script language='JavaScript'>"
"setTimeout(function(){location.reload()},1000);"
"</script>"
"</ul>"
"</div>"
"</div>"
"<div class='clear'></div>"
"</div>"
"</body>"
"</html>";

String datos = datos0 + datos1;


/*
 * Funcion Setup
 */

void setup(void) {
  Serial.begin(115200);

  SerialDisplay.begin(9600);      /* SoftwareSerial para poder comunicarse con el display */

  /* Inicializar display */
  genie.Begin(SerialDisplay);     /* Asignar el puerto serie al display */
  pinMode(RESETLINE, OUTPUT);     /* Inicializar pin RES como salida */
  digitalWrite(RESETLINE, 0);     /* 0 en RES para resetear el display */
  delay(1000);                    /* Delay para que se resetee debidamente el display */
  digitalWrite(RESETLINE, 1);     /* 1 en RES para no resetear el display */
  delay(4500);                    /* Delay para que se inicialice el display */
  genie.WriteContrast(15);        /* Valor de 0 a 15 para ajustar el contraste (0 es display apagado) */

  /* Connect to WiFi network */
  WiFi.begin(ssid, password);
  Serial.println("");

  /* Wait for connection */
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  /* OTA Updater */

  /* use mdns for host name resolution */
  if (!MDNS.begin(host)) { //http://sbc21g09.local
    Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("mDNS responder started");
  /*return index page which is stored in serverIndex */
  server.on("/", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/html", loginIndex);
  });
  server.on("/serverIndex", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/html", serverIndex);
  });
  server.on("/datos", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/html", datos);
  });
  /*handling uploading firmware file */
  server.on("/update", HTTP_POST, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
    ESP.restart();
  }, []() {
    HTTPUpload& upload = server.upload();
    if (upload.status == UPLOAD_FILE_START) {
      Serial.printf("Update: %s\n", upload.filename.c_str());
      if (!Update.begin(UPDATE_SIZE_UNKNOWN)) { //start with max available size
        Update.printError(Serial);
      }
    } else if (upload.status == UPLOAD_FILE_WRITE) {
      /* flashing firmware to ESP*/
      if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
        Update.printError(Serial);
      }
    } else if (upload.status == UPLOAD_FILE_END) {
      if (Update.end(true)) { //true to set the size to the current progress
        Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
      } else {
        Update.printError(Serial);
      }
    }
  });

  server.begin();

  /* Se inicializa la conexion I2C en los pines 4 y 15 */
  Wire.begin(4,15);

  /* Se inicializa como entrada el pin 21 referente al sensor de nivel del agua */
  pinMode(PIN_NIVEL_AGUA, INPUT);

  /* Se inicializa como salida el pin 23 referente a la bomba de agua */
  pinMode(PIN_BOMBA, OUTPUT);

  pinMode(PIN_TURBIDITY, INPUT);

  /* Se inicializa el sensor BME280 en la direccion 0x76 */
  bme.begin(0x76);

  /* Se inicializa el led RGB WS2812B */
  ledRGB.begin();

  /* Se inicializa el sensor de luz BH1750 */
  sensorLuz.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x5C, &Wire);

  /*
   * Inicializar el reloj DS3231 (solo se realiza una vez)
   *
   * setDS3231time(00, 40, 15, 3, 02, 12, 2021);
   *
   */
}


/*
 * Funcion Loop
 */

void loop(void) {
  double temp, hum, lux, voltage, pres;
  int turbidez;
  byte segundos, minutos, hora, diaSemana, diaMes, mes, anio;
  boolean nivel_agua;
  
  rtc_hold_dis_pines();     /* Disable hold pins */

  genie.WriteObject(GENIE_OBJ_USER_LED, 0, false);   /* Apagar el led indicador del Sleep Mode */

  server.handleClient();
  delay(10);
  
  /* Obtener lectura de los sensores */
  readDS3231time(&segundos, &minutos, &hora, &diaSemana, &diaMes, &mes, &anio);  /* Lectura del RTC */
  lux = sensorLuz.readLightLevel();                                              /* Lectura del sensor luz */
  temp = bme.readTemperature();                                                  /* Lectura del sensor temperatura */
  hum = bme.readHumidity();                                                      /* Lectura del sensor humedad */
  pres = bme.readPressure() / 100.0F;                                            /* Lectura del sensor presion */
  voltage = analogRead(PIN_TURBIDITY) * (5.0 / 1024.0);                          /* Lectura del conversor analogico-digital del sensor de turbidez */
  turbidez = int(voltage*(4550.0/5.0));                                          /* Conversion del valor de la turbidez a su correspondiente unidad (NTU) */
  nivel_agua = digitalRead(PIN_NIVEL_AGUA);                                      /* Lectura del sensor de nivel de agua */

  digitalWrite(PIN_BOMBA, HIGH);                                                 /* Se enciende la bomba de agua */
  
  /* Eventos a actualizar en el display */
  genie.DoEvents();  /* Funcion que se encarga de procesar las respuestas del display */
  genie.WriteStr(1, temp, 2);
  genie.WriteStr(5, hum, 2);
  genie.WriteStr(3, lux, 2);
  genie.WriteStr(4, pres, 2);
  if(turbidez > 4550)
    genie.WriteStr(6, "NC");
  else
    genie.WriteStr(6, turbidez, 2);
  if(nivel_agua) {
    genie.WriteStr(2, "No hay agua");
  }
  else {
    genie.WriteStr(2, "Hay agua");
  }

  /* Mostrar fecha */
  Serial.print(hora, DEC); Serial.print(":"); Serial.print(minutos, DEC); Serial.print(":"); Serial.print(segundos, DEC); Serial.println("");
  delay(1000);
  
  /* Valoracion de las lecturas con respecto a los valores de referencia segun sea de dia o de noche */
  /* Ciclo de dia */
  if(hora >= 8 && hora <= 19) {
    cicloDia(temp, hum);
    ajustar_Temperatura_Display_Dia(temp);
    ajustar_Humedad_Display_Dia(hum);
    ajustar_Luz_Display_Dia(lux);
  }

  /* Ciclo de noche */
  else {
    cicloNoche(temp, hum);
    ajustar_Temperatura_Display_Noche(temp);
    ajustar_Humedad_Display_Noche(hum);
    ajustar_Luz_Display_Noche(lux);
  }
  
  /* Comprobar cantidad luz en las horas determinadas */
  Serial.print("Cantidad de luz: ");
  Serial.print(lux);
  Serial.println(" lux");
  if(hora >= 10 && hora <= 16) {      /* Horas del dia en las que mas luz necesita */
    if(lux < LUZ_DIA_BAJA)
      Serial.println("La planta necesita mas luz");
  }
  
  /* Actualizacion de los datos en la web */
  datos = datos0 
  +"<li style='color:#AED6F1;font-size:150%'>"+"Temperatura : "+ bme.readTemperature() + "*C\n"+"</li>" 
  +"<li style='color:#AED6F1;font-size:150%'>"+"Intensidad Luz : " + sensorLuz.readLightLevel() + "lux\n" +"</li>"
  +"<li style='color:#AED6F1;font-size:150%'>"+"Nivel Agua : " + digitalRead(PIN_NIVEL_AGUA)+"</li>"
  +"<li style='color:#AED6F1;font-size:150%'>"+"Presion : " + bme.readPressure() / 100.0F + " hPa"+"<li>" 
  +"<li style='color:#AED6F1;font-size:150%'>"+"Humedad : " + bme.readHumidity() + "%" +"</li>"
  +"<li style='color:#AED6F1;font-size:150%'>"+"Turbidez : " + analogRead(PIN_TURBIDITY) * (5.0 / 1024.0) + "v" +"</li>"
  +"<li style='color:" + informacion +"</li>"+datos1;
  
  /* Enviar las lecturas a ThingsBoard */
  if ( !tb.connected() ) {
    reconnectTB();
  }
  subirDatosThingsBoard(temp, hum, lux, pres, turbidez, nivel_agua);
  tb.loop();
  
  /* Sleep Mode */
  delay(15000);     /* Delay solo para la demostracion del Sleep Mode, en implementacion real hay que quitarlo */
  genie.WriteObject(GENIE_OBJ_USER_LED, 0, true);   /* Encender el led indicador del Sleep Mode */
  rtc_hold_en_pines();     /* Enable hold pines */

  goToDeepSleep();         /* Enviar al procesador a domir (Deep Sleep) */
  //goToLightSleep();      /* Enviar al procesador a domir (Light Sleep) */
}
