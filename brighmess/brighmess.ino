int led=11;
int in=A0;
int invalue;

void setup() {

  Serial.begin(9600);
  pinMode(in,INPUT);
  
}

void loop() {


    invalue=analogRead(in);

    analogWrite(led,invalue/4); 

    Serial.println(invalue/4);
    delay(1000);
}
