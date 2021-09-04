
 
 #include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      mySerial.println("AT+CHFA=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
      mySerial.println("AT+CMIC=1");
      
     mySerial.println("ATD\"918080073317\"\r"); // Replace x with mobile number
     delay(1000);
          
      break;


 
    case 'r':
      mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
      delay(1000);
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}
