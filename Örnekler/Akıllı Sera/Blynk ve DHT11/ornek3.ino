#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "";
char ssid[] = "";
char pass[] = "";

#define DHTPIN 4          
#define role 2 

#define DHTTYPE DHT11    

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;


void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V0, t);

}

void setup()
{

  Serial.begin(9600);pinMode(role,OUTPUT);

  Blynk.begin(auth, ssid, pass);


  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{

  Blynk.run();
  timer.run();
}
