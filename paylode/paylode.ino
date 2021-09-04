/*
 * Generated with <3 by Dckuino.js, an open source project !
 */

#include "DigiKeyboard.h"

void typeKey(int key)
{
  DigiKeyboard.press(key);
  delay(50);
  DigiKeyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  DigiKeyboard.begin();

  // Wait 500ms
  delay(500);

  // Lock Me 0.3 - Script opens Notepad and types a message concerning locking the computer - by SurfKahuna (RJC)
  delay(500);

  DigiKeyboard.press(KEY_LEFT_GUI);
  DigiKeyboard.press('r');
  DigiKeyboard.releaseAll();

  delay(200);

  DigiKeyboard.print("notepad.exe");

  typeKey(KEY_RETURN);

  delay(300);

  DigiKeyboard.print("          , ,\\ ,'\\,'\\ ,'\\ ,\\ ,");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("    ,  ,\\/ \\' `'     `   '  /|");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("    |\\/                      |");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("    :                        |");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("    :                        |");

 
  DigiKeyboard.print("I will learn to lock my computer.");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("I will learn to lock my computer.");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("I will learn to lock my computer.");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("I will learn to lock my computer.");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("I will learn to lock my computer.");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("I will learn to lock my computer.");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("I will learn to lock my computer.");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("I will learn to lock my computer.");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("I will learn to lock my computer.");

  typeKey(KEY_RETURN);

  DigiKeyboard.print("I will learn to lock my computer.");

  typeKey(KEY_RETURN);

  typeKey(KEY_RETURN);

  
  delay(100);


  DigiKeyboard.print("x");

  delay(50);

  
  DigiKeyboard.end();
}

/* Unused endless loop */
void loop() {}
