
  int pin1=8;
  int pin2=9;
  int pin3=10;
  int pin4=11;
  int cnt=1;

  String input;

void setup()
{
    pinMode(pin1,OUTPUT);
    pinMode(pin2,OUTPUT);
    pinMode(pin3,OUTPUT);
    pinMode(pin4,OUTPUT);

    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);

    Serial.begin(9600);

}

void loop() 
{

      if(Serial.available()>0)
      {
          input=Serial.readString();

          if(input=="start")
          {
              digitalWrite(pin3,HIGH);
              digitalWrite(pin4,HIGH);
              delay(2000);
              digitalWrite(pin4,LOW);
              digitalWrite(pin3,LOW);  
          }
          
          if(input=="go")
          {
            if(cnt<=5)
            {
              digitalWrite(pin3,LOW);
              digitalWrite(pin1,HIGH); 
              delay(5000);
              cnt++;
              digitalWrite(pin1,LOW); 
            }
            else
            {
                Serial.println("speed is maximum "); 
            }
          }
          if(input=="slow")
          {
            if(cnt>=1)
            {
              digitalWrite(pin2,HIGH);
              delay(1800);
              cnt--;
              digitalWrite(pin2,LOW);
            }
            else
            {
              Serial.println("speed is minimum");
            }
          }
          if(input=="stop")
          {
            
              digitalWrite(pin2,HIGH);
              while(cnt>=1)
              {    
                digitalWrite(pin3,HIGH);
                delay(300);
                digitalWrite(pin3,LOW);
              
                delay(1500);
                cnt--;
              }
              digitalWrite(pin2,LOW);   
              digitalWrite(pin3,HIGH);          
          }
      }
}
