int a0=A3;
int a1=A4;
int a2=A5;
int x,y,z;
void setup() {

  Serial.begin(9600);

  pinMode(a0,INPUT);
  pinMode(a1,INPUT);
  pinMode(a2,INPUT);
  
  
}

void loop() {


  x=analogRead(a0)-300;
  Serial.print("X : ");
  Serial.print(x);

  y=analogRead(a1)-300;
  Serial.print(" Y : ");
  Serial.print(y);
  
  z=analogRead(a2)-300;
  Serial.print(" Z : ");
  Serial.print(z);

  
   if(x >=5 && x <= 20)
   {
     Serial.println("  bike is straight ");
   }
   else if(x >= -20 && x < 5)
   {
    Serial.println("  bike does a left turn");
   }
   else if(x > 20 && x <= 40)
   {
      Serial.println("  bike does a right turn");
   }
   else if(y >= 307 && y <= 329)
   {
      Serial.println("  bike does wheelie"); 
   }
   else
   {
    Serial.println("  bike is fucked!!!!!!"); 
   }

   Serial.println("");
  delay(2000);

}
