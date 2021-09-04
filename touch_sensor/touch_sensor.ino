int in1=1,in2=2,in3=3,in4=4,in5=5,in6=6;
int out1=7,out2=8,out3=9,out4=10,out5=11,out6=12;

char state1,state2,state3,state4,state5,state6;

void setup() {

  pinMode(in1,INPUT);
  pinMode(in2,INPUT);
  pinMode(in3,INPUT);
  pinMode(in4,INPUT);
  pinMode(in5,INPUT);
  pinMode(in6,INPUT);
 
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
  pinMode(out5,OUTPUT);
  pinMode(out6,OUTPUT);

  Serial.begin(9600);
  digitalWrite(out1,LOW);

  
}

void loop() {
  
  
 /* if(in1==HIGH)
  {
      if(state1==1) 
      {
        digitalWrite(out1,HIGH);
        state1=1;
      }
      else
      {
        digitalWrite(out1,LOW);
        state1=0;  
      }
   }*/
  
   state1=digitalRead(in1);
  if(state1>1)
  {
      digitalWrite(out1,HIGH);
  }
  if(state1==0)
  {
       digitalWrite(out1,LOW);
  }

}
