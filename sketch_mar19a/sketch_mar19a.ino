 int pin1=8;
int pin2=9;

void setup() {
  // put your setup code here, to run once:
 pinMode(pin1,OUTPUT);
 pinMode(pin2,OUTPUT);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

    digitalWrite(pin1,HIGH);
    delay(25000);
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
    delay(9000);
    digitalWrite(pin2,LOW);

}
