#include <Blynk.h>



//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define RED D6
#define GREEN D7
#define BLUE D8

#define BLYNK_AUTH_TOKEN "fpXf5p34r6S8enR5Dl59pYUmLt50IZPq"


char auth[] = "fpXf5p34r6S8enR5Dl59pYUmLt50IZPq";
char ssid[] = "Robotistan";
char pass[] = "bmc34RbT124";

//Get the button values
BLYNK_WRITE(V0){
    int pinvalue = param.asInt();
    digitalWrite(RED,pinvalue);
}
  BLYNK_WRITE(V1){
    int pinvalue = param.asInt();
    digitalWrite(GREEN,pinvalue);
}
  BLYNK_WRITE(V2){
    int pinvalue = param.asInt();
    digitalWrite(BLUE,pinvalue);
}

void setup() {
  //Set the relay pins as output pins
  Serial.begin(115200);
  delay(100);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}
