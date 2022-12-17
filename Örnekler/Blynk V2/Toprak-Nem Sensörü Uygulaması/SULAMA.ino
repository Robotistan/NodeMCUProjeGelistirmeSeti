
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLTjsv-STs"
#define BLYNK_DEVICE_NAME "toprak"
#define BLYNK_AUTH_TOKEN "ToKiwVM9ukEgJX3D2RIk65feeNINVG4B"



#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


BlynkTimer timer;
int nemPin = A0;


int nemdegeri;
int nemEsikdegeri = 270;

char auth[] = "ToKiwVM9ukEgJX3D2RIk65feeNINVG4B";
      char ssid[] = "Robotistan";
      char pass[] = "bmc34RbT124";

void setup()
{
  pinMode(nemPin, INPUT);
  Blynk.begin(auth, ssid, pass);
                       timer.setInterval(1000L,sendData);
  Serial.begin(115200);
}
void sendData()
{
  
  nemdegeri = analogRead(nemPin);

  Serial.print("Direnç Değeri: ");
  Serial.println(nemdegeri);

  if(nemdegeri < nemEsikdegeri)
  {
      Serial.println("Ortam ISLAK SULAMA GEREKMİYOR");
   
    
  }
  else
  {
    Serial.println("Ortam KURU SULAMA YAPILMASI GEREK");
   
  }
  delay(1000);
  Blynk.virtualWrite(V0,nemdegeri);
  }
void loop()
{
{
  Serial.println(nemdegeri);
    delay(200);
}
Blynk.run();
  timer.run();
}
