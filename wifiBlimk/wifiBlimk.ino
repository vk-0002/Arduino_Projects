int pin=D0;

void setup() {
  // put your setup code here, to run once:

  pinMode(pin,OUTPUT);

    Serial.println("hii");

  digitalWrite(pin,LOW);

}

void loop() {

  digitalWrite(pin,HIGH);
  delay(2000);
  digitalWrite(pin,LOW);
  delay(2000);
  // put your main code here, to run repeatedly:

}
