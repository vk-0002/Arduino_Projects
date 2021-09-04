int out=13;
int in=12;

void setup() {
  
    Serial.begin(9600);

    pinMode(out,OUTPUT);
    pinMode(in,INPUT);
    
}

void loop() {

int  s=digitalRead(in);
  if(s==HIGH)
  {
    Serial.println("1");
    digitalWrite(out,HIGH);
    }
    else{

      Serial.println("0");
        
        digitalWrite(out,LOW);
      }
  

}
