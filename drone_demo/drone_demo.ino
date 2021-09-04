int pin1=12;
int out=11;
int in=A0;
void setup() {
  // put your setup code here, to run once:

  pinMode(pin1,OUTPUT);
  pinMode(in,INPUT);
  pinMode(out,OUTPUT);

  digitalWrite(pin1,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

 
    int a=analogRead(in);

    analogWrite(out,a/4);


}
