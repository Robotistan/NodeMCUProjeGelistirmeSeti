const int toprak =A0;
int motor =7;
void setup() {
Serial.begin(9600);
pinMode(7,OUTPUT);
}

void loop() {
 int olcum_sonucu = analogRead(toprak);
Serial.println(olcum_sonucu);
if (olcum_sonucu <=400){
  digitalWrite(7,1);
}
else{
  digitalWrite(7,0);
}
}
