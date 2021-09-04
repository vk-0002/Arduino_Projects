/*Typical pin layout used:
   --------------------------------------------------------------------------------------------------
               MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino      esp
               Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
   Signal      Pin          Pin           Pin       Pin        Pin              Pin
   ---------------------------------------------------------------------------------------------------
   RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST           D3
   SPI SS      SDA(SS)      10            53        D10        10               10            D4
   SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16            D7
   SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14            D6
   SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15            D5
*/



#include <SPI.h>
#include <MFRC522.h>
#include<ESP8266WiFi.h>

const char* ssid="vaibhav";
const char* password="0987654321";
const char* host="iot-vaibhav.000webhostapp.com";

#define SS_PIN D4
#define RST_PIN D3

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

void setup() 
{
  Serial.begin(115200);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  
  
  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED)
  {
      delay(500);
      Serial.print(".");
    }

   Serial.println("");
   Serial.println("WiFi connected ");
   Serial.println("IP address : ");
   Serial.println(WiFi.localIP());
   Serial.println("Netmast : ");
   Serial.println(WiFi.subnetMask());
   Serial.println("Gateway : ");
   Serial.println(WiFi.gatewayIP());

   
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Put your card to the reader...");
  Serial.println();

}

void loop() 
{

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


  // removing space for avoid bad request error

  char id[10];

  int j=0;
  for(int i=0;content[i]!='\0';i++)
  {
      if(content[i]!=' ')
      {
          id[j]=content[i];
          j++;        
      }
  }
  id[j]='\0';

  content=String(id);
 
  Serial.println();
  Serial.print("Message : ");

  content.toUpperCase();
  
  Serial.print("connecting to ");
  Serial.println(host);


  WiFiClient  client;

  const int httpPort=80;

  if(!client.connect(host, httpPort))
  {
      Serial.println("connection fail !!!!!!!!!!");
      return;
    }


   String url = "http://iot-vaibhav.000webhostapp.com/api/msg/insert.php?msg=" + String(content);
  Serial.print("Requesting URL: ");
  Serial.println(url);
 
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  
  delay(500);
  
  while(client.available())
  {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }

    Serial.println("");
    Serial.println("connection close ");
    delay(1000);
}
