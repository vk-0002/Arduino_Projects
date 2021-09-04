const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  7;      // the number of the LED pin

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin);
 //delay(400);
  //buttonState2 = digitalRead(buttonPin);

Serial.println(buttonState1);
  
  if(buttonState1==0 )
  {
      digitalWrite(ledPin,HIGH);
     // Serial.println(buttonState1);
  }
  else
  digitalWrite(ledPin,LOW);
  

}
