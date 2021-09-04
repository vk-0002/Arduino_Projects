String card="";
char c;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(96000);
}

void loop() {
  // put your main code here, to run repeatedly:

    int i=0;

    card="";

  for(i=0;i<12;i++)
  {
     if(Serial.available()>0)
      {
          c=Serial.read();
          card=card+c;
        }
  }

  Serial.println(card);
}
