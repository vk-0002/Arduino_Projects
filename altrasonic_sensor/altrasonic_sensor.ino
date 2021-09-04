int trans = 11;
int res = 12;
int led = 13;
int distance;
long duration;

void setup() {

  Serial.begin(9600);
  pinMode(trans, OUTPUT);
  pinMode(res, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  digitalWrite(trans, LOW);
  delay(2);

  digitalWrite(trans, HIGH);
  delay(10);
  digitalWrite(trans, LOW);

  duration = pulseIn(res, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("distance : ");
  Serial.println(distance);

  if (distance >  110)
  {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }

  if (distance <= 110 && distance > 60)
  {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }

  if (distance <= 60 && distance > 18)
  {
    digitalWrite(led, HIGH);
    delay(300);
    digitalWrite(led, LOW);
    delay(300);
  }


}
