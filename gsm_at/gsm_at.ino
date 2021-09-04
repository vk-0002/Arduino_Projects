#include<SoftwareSerial.h>

SoftwareSerial gsm(9,10);

void setup() {

    Serial.begin(9600);
    gsm.begin(9600);
 
}

void loop() {


 
  if(gsm.available())
  {
      Serial.println(gsm.read());
    }

  if(Serial.available())
 {

    byte v=Serial.read();

    if(v=='$')
    {
        gsm.write(char(26));
      }
    else
    {
        gsm.write(v);
      }

    

    
  }
}
