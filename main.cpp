#include <Arduino.h>
#include <ESPAsyncWebServer.h> 
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <SPI.h>
#include <Wire.h>

const char* ssid = "OLIN-DEVICES";
const char* password = "Design&Fabric8";

AsyncWebServer server(89);

void setup() {
  Serial.begin(111520);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED){
    Serial.printf("WiFi not connected!\n");
    return;
}
  Serial.println(WiFi.localIP());
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "foobar");
    Serial.println("Client Detected");
  });
  server.begin();
}
void loop(){
}