int ledPin1=13;
int ledPin2=12;
int ledPin3=11;
int ledPin4=10;

String input;

void setup() 
{
  
   pinMode(ledPin1,OUTPUT);
   pinMode(ledPin2,OUTPUT);
   pinMode(ledPin3,OUTPUT);
   pinMode(ledPin4,OUTPUT);
   
   digitalWrite(ledPin1,LOW);
   digitalWrite(ledPin2,LOW);
   digitalWrite(ledPin3,LOW);
   digitalWrite(ledPin4,LOW);
   
  Serial.begin(9600);

}
void loop() 
{ 
 
  if(Serial.available()>0)
  {
      input=Serial.readString();

      if(input=="turn on all"||input=="jarvis turn on all")
      {
          digitalWrite(ledPin1,HIGH);
          digitalWrite(ledPin2,HIGH);
          digitalWrite(ledPin3,HIGH); 
          digitalWrite(ledPin4,HIGH);
      }
      
      if(input=="turn off all"||input=="jarvis turn off all")
      {
          digitalWrite(ledPin1,LOW);
          digitalWrite(ledPin2,LOW);
          digitalWrite(ledPin3,LOW);
          digitalWrite(ledPin4,LOW);
      }

        if(input=="green LED chalu kar"||input=="turn on green LED"||input=="jarvis turn on green LED")
        {
              digitalWrite(ledPin1,HIGH);
        }
        if(input=="green LED band kar"||input=="turn off green LED"||input=="jarvis turn off green LED")
        {
            digitalWrite(ledPin1,LOW);
            
        }

        if(input=="TV chalu kar"||input=="turn on TV"||input=="jarvis turn on TV")
        {
            digitalWrite(ledPin2,HIGH);
          }
        if(input=="TV band kar"||input=="turn off TV"||input=="jarvis turn off TV")
        {
            digitalWrite(ledPin2,LOW);
        }

        if(input=="bulb chalu kar"||input=="turn on bulb"||input=="jarvis turn on bulb")
        {
            digitalWrite(ledPin3,HIGH);
          }

         
        if(input=="bulb band kar"||input=="turn off bulb"||input=="jarvis turn off bulb")
        {
            digitalWrite(ledPin3,LOW);
          } 
        
        if(input=="charger chalu kar"||input=="turn on charger"||input=="jarvis turn on charger")
        {
            digitalWrite(ledPin4,HIGH);
        }

         if(input=="charger band kar"||input=="turn off charger"||input=="jarvis turn off charger")
        {
            digitalWrite(ledPin4,LOW);
        }
  }
}
