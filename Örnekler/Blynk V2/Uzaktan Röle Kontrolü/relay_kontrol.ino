#include <Blynk.h>




#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define relay1 D0
#define relay2 D1

#define BLYNK_AUTH_TOKEN "JZzzHj1lQWHhVrkrwR5jdZeyZyqSjYr9"


char auth[] = "JZzzHj1lQWHhVrkrwR5jdZeyZyqSjYr9";
char ssid[] = "Robotistan";
char pass[] = "bmc34RbT124";


BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  
  if (value1 == 1) {
    digitalWrite(relay1, LOW);
  } else {
    digitalWrite(relay1, HIGH);
  }
}


BLYNK_WRITE(V1) {
  bool value2 = param.asInt();
  
  if (value2 == 1) {
    digitalWrite(relay2, LOW);
  } else {
    digitalWrite(relay2, HIGH);
  }
}

void setup() {
  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);


  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);

  
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}
