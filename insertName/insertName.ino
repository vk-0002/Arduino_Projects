
#include <ESP8266WiFi.h>
#include<DHT.h>

const char* ssid     = "vaibhav";
const char* password = "0987654321";
const char* host = "iot-vaibhav.000webhostapp.com";

String s="";

void setup() {
  Serial.begin(115200);
  delay(100);
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
}
void loop() {


  
      Serial.print("connecting to ");
      Serial.println(host);

      WiFiClient client;
     const int httpPort = 80;
  
    if (!client.connect(host, httpPort)) {
       Serial.println("connection failed");
        return;
     }
  
     String url = "http://iot-vaibhav.000webhostapp.com/api/name/insert.php?pname=hiiii";
      Serial.print("Requesting URL: ");
      Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
 
  
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
    
  }
  
  Serial.println();
  Serial.println("closing connection");
  delay(3000);
}
