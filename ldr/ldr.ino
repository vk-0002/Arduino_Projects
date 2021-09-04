int in=A0;
int out=11;

void setup() {
  
  Serial.begin(9600);
  pinMode(in,INPUT);
   pinMode(out,OUTPUT);
   

}

void loop() {

  int sensor=analogRead(in);

//  if(sensor==HIGH)
//  {
      analogWrite(out,sensor);
    
    
//    }
//else
//{
//digitalWrite(out,LOW);
//}
  

}
