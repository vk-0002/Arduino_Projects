int led=13;
void setup() {
  // put your setup code here, to run once:
  digitalWrite(led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led,LOW);
delay(1000);
digitalWrite(led,HIGH);
delay(2000);
}
