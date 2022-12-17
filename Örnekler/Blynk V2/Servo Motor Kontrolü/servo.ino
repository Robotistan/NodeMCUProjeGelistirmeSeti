#include <Servo.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL_VnvMgsf"
#define BLYNK_DEVICE_NAME "motor"
#define BLYNK_AUTH_TOKEN "GJQ0PWuVgtF6acLnLPQ2Tn0-qdgOb0xX"
#define USE_NODE_MCU_BOARD
//#include "BlynkEdgent.h"
Servo servo;
 char auth[] = "GJQ0PWuVgtF6acLnLPQ2Tn0-qdgOb0xX";
  char ssid[] = "Robotistan";
  char pass[] = "bmc34RbT124";
 
BLYNK_WRITE(V0){
  int s0 = param.asInt(); 
  servo.write(s0);
  Blynk.virtualWrite(V0, s0);
}
void setup() {
  Serial.begin(9600);
  servo.attach(D1);
  Blynk.begin (auth, ssid, pass, "blynk.cloud", 80);
}
 
void loop() {
  Blynk.run();
}
