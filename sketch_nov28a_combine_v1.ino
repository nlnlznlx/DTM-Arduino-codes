#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;
int sensor = 2;
int button1 = 4;
int button2 = 3;
int state = 1;

void setup() {
  lcd.begin(16, 2);    
  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("Grab a book!");
  delay(1000);

  pinMode(sensor, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Intial state (How to start the game: grab a book)
  if (state == 1){
    lcd.clear();
    lcd.setRGB(255, 255, 255);
    lcd.print("Grab a book!");
    delay(300);
    if (digitalRead(sensor) == LOW)
      state = 2;
    else if (digitalRead(button1) == 1)
      state = 3;
    else if (digitalRead(button2) == 1)
      state = 4;
  }
  // Fist state: success
  else if (state == 2){
      lcd.clear();
      lcd.setRGB(0, 255, 0);
      lcd.print("Success!");
      delay(100);
      if (digitalRead(sensor) == HIGH)
        state = 1;
  }  
  // Second state: Earlier
  else if (state == 3){
      lcd.clear();
      lcd.setRGB(255, 255, 0);
      lcd.print("Earlier!");
      delay(100);
      if (digitalRead(button1) == 1)
        state = 1;
  } 
  // Third state: Later
  else if (state == 4){
      lcd.clear();
      lcd.setRGB(0, 0, 255);
      lcd.print("Later!");
      delay(100);
      if (digitalRead(button2) == 1)
       state = 1;
  } 
  delay(80);
  //Serial.println(digitalRead(sensor)); 
}



