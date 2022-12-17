
#define BLYNK_TEMPLATE_ID "TMPLfhumIU5X"
#define BLYNK_DEVICE_NAME "gaz"
#define BLYNK_AUTH_TOKEN "iJoImB-TXwpaUbYFXBleUeHtK_rEgLvl"
#define GreenLed 14 
#define RedLed 12 


#define MQ2pin (A0)
#define BLYNK_PRINT Serial
#define buzzerPin 0 
#define GreenLed 14 
#define RedLed 12 

#include <SPI.h>
#include <BlynkSimpleEsp8266.h>]

BlynkTimer timer;
char auth[] = "iJoImB-TXwpaUbYFXBleUeHtK_rEgLvl";
char ssid[] = "Robotistan";
  char pass[] = "bmc34RbT124";

float sensorValue;


int n,m;

void setup()
{

  Serial.begin(115200);
  Serial.println("Gas sensor warming up!");
  delay(5000);

  Blynk.begin(auth, ssid, pass);
 
  
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(12,OUTPUT);

  pinMode(16,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  digitalWrite(GreenLed, LOW);
  digitalWrite(RedLed, LOW);
  timer.setInterval(1000L, sendUptime);
}


void sendUptime()
{
  Blynk.virtualWrite(V0, sensorValue);  
  
}

void loop()
{
  
  sensorValue = analogRead(MQ2pin); 
  
  Serial.println("");
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.println("");
  Serial.println("");
  Serial.print("smoke: ");
  Serial.print(A0);
  Serial.println("");
  Blynk.virtualWrite(V0, sensorValue);
  if(sensorValue > 300 && sensorValue < 600)
  {
    Serial.print("Smoke detected!");
  }
  
  
  n=analogRead(A0);

  if(n>600)
  {
  
    n==m;
    m=analogRead(A0);
    Serial.println(m);
    
  }
  if(n>300 && n<600)
  {
    digitalWrite(D3,LOW);
    digitalWrite(D6,HIGH); 
    digitalWrite(D5,LOW);
    tone(buzzerPin,800,80);
    delay(2000);  
  }
  
  if(n<300)
  {
      digitalWrite(D5,HIGH );
      digitalWrite(D3,LOW);
      digitalWrite(D6,LOW);
      delay(2000);
      noTone(buzzerPin);
  }

  Blynk.run();
}
