void setup() {
  // put your setup code here, to run once:
    int a,b,c;

    Serial.begin(9600);
    if(Serial.available()>0){
    a=Serial.read();
    b=Serial.read();

    c=a+b;

    Serial.println(c);

    }
}

void loop() {
  // put your main code here, to run repeatedly:

}
