#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h>    
LiquidCrystal_I2C lcd(0x27,16,2); 
virtuabotixRTC myRTC(5, 4, 3);
const int toprak = A0;
int olcum_sonucu ;
int buzzer = 7;

void setup() {
lcd.begin();
myRTC.setDS1302Time(00, 56, 10,7, 1, 7, 2021); // saniye,dakika,saat,haftanın günleri,gün,ay,yıl  bu şekilde ilk önce ayarlayıp daha sonra bu kısmı silebiliriz.
} 
              
void loop() {
myRTC.updateTime();
if(myRTC.hours == 15 && myRTC.minutes == 00 && myRTC.seconds == 00)   // Saat 3 olduğu zaman buraya girecek.
              {
lcd.setCursor(1,0);
lcd.print("  Hikaye Saati   ");
lcd.setCursor(0,1);
lcd.print("Hikaye Okurmusun");
digitalWrite(7, HIGH);
delay(1000);
digitalWrite(7,LOW);
delay(1000);
digitalWrite(7, HIGH);
delay(1000);
digitalWrite(7,LOW);
delay(1000);
digitalWrite(7, HIGH);
delay(1000);
digitalWrite(7,LOW);
delay(1000);
    }
olcum_sonucu = analogRead(toprak);
 if (olcum_sonucu <=400){
  digitalWrite(7, HIGH);
   lcd.setCursor(1,0);
 lcd.print("    Susadim    ");
  lcd.setCursor(0,1);
 lcd.print("Beni Sularmisin?");
 delay(5000);
 lcd.clear(); 

}
 if (olcum_sonucu >=400){
    digitalWrite(7, LOW);
 }
// Şimdi değerleri okuyalım
lcd.setCursor(1,0);
lcd.print("Tarih:");
lcd.print(myRTC.dayofmonth);
lcd.print("/");
lcd.print(myRTC.month);
lcd.print("/");
lcd.print(myRTC.year);
lcd.setCursor(0,1);
lcd.print(" Saat :");
lcd.print(myRTC.hours);
lcd.print(":");
lcd.print(myRTC.minutes);
lcd.print(":");
lcd.print(myRTC.seconds);
delay(1);
}
