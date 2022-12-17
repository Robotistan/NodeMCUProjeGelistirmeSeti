int role= 7; 

void setup(){
Serial.begin(9600); 
pinMode(7, OUTPUT);

}
  void loop(){
    
    if(Serial.available())
    {
      int data=Serial.read();
      delay(100);
     
     if(data=='1') { 
    digitalWrite(7,HIGH); 
    }  
    if(data=='2'){
     digitalWrite(7,LOW); 
    }

    }
  }
  
