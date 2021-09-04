/*Typical pin layout used:
   -----------------------------------------------------------------------------------------
               MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
               Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
   Signal      Pin          Pin           Pin       Pin        Pin              Pin
   -----------------------------------------------------------------------------------------
   RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
   SPI SS      SDA(SS)      10            53        D10        10               10
   SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
   SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
   SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
*/



#include <SPI.h>
#include <MFRC522.h>
  
#define SS_PIN 10
#define RST_PIN 9
int lock=4;
int pushbutton=7;

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

void setup() 
{
  Serial.begin(115200);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

 
  Serial.println("Put your card to the reader...");
  Serial.println();

  pinMode(pushbutton,INPUT_PULLUP);
  pinMode(lock,OUTPUT);
  digitalWrite(lock,HIGH);
  
  
}

//void (* reset) (void)=0;  // reset line
void loop() 
{

    //for push button

    if(digitalRead(pushbutton)==LOW)
    {
        
      Serial.println("Push button pressed");
      Serial.println(); 
      digitalWrite(lock,LOW);  
      delay(1500);
      digitalWrite(lock,HIGH);
      
    }

  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {  
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i],HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");

  content.toUpperCase();
  if (content == " CB 6F 01 0C" ||content == " 4B BC D8 73" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    digitalWrite(lock,LOW);
    delay(1500);
    digitalWrite(lock,HIGH);
  }
 
 else  
 {
    Serial.println(" Access denied");
   delay(2000);
  }
 // reset(); 
}
