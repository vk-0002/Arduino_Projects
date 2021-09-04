#include "DigiKeyboard.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(1,OUTPUT);
  digitalWrite(1,HIGH);


  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  DigiKeyboard.print("terminal\n");
  DigiKeyboard.delay(500);
  
  DigiKeyboard.sendKeyStroke(KEY_T,MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
  DigiKeyboard.delay(500);

  DigiKeyboard.print("nano v.c\n");
 // DigiKeyboard.print(500);

  //DigiKeyboard.print("i");
  //DigiKeyboard.print(500);

  DigiKeyboard.print("#include<stdio.h>\n");
  DigiKeyboard.print("int main()\n{\n");
  DigiKeyboard.print("printf(\"hello world \");\n");  
  DigiKeyboard.print("}\n");
  
  DigiKeyboard.sendKeyStroke(KEY_X,MOD_CONTROL_LEFT);
 // DigiKeyboard.print(500);
  DigiKeyboard.print("y\n");

  //DigiKeyboard.print("!:wq\n");
  //DigiKeyboard.print(500);

  DigiKeyboard.print("gcc v.c\n");
  DigiKeyboard.delay(2000);

  DigiKeyboard.print("./a.out\n");
  
  digitalWrite(1,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

}
