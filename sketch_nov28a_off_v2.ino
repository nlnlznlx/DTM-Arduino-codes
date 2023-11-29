#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 100;
const int colorG = 100;
const int colorB = 100;
int sensor = 2;
int button1 = 4;
int button2 = 3;
int state = 0;

void setup() {
  lcd.begin(16, 2);    
  lcd.setRGB(colorR, colorG, colorB);
  delay(1000);

  pinMode(sensor, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Intial state (screen light off until students take out the first book)
  if (state == 0){
    lcd.clear();
    lcd.setRGB(0, 0, 0);
    delay(100);
    if (digitalRead(sensor) == LOW)
      state = 2;  
    else if (digitalRead(button1) == 1)
      state = 3;
    else if (digitalRead(button2) == 1)
      state = 4;
    delay(300);  
  }
  // Fist state: intermezzo
  else if (state == 1){
    lcd.clear();
    lcd.setRGB(colorR, colorG, colorB);
    lcd.print("Grab a book!");
    delay(300);
    if (digitalRead(sensor) == LOW)
      state = 2;  
    else if (digitalRead(button1) == 1)
      state = 3;
    else if (digitalRead(button2) == 1)
      state = 4;  
  }
  // Second state: success
  else if (state == 2){
    lcd.clear();
    lcd.setRGB(0, 120, 0);
    lcd.print("Success!");
    delay(100);
    if (digitalRead(sensor) == HIGH)
      state = 1;    
  } 
  // Third state: Earlier
  else if (state == 3){
    lcd.clear();
    lcd.setRGB(120, 120, 0);
    lcd.print("Earlier!");
    delay(150);
    if (digitalRead(button1) == 1)
      state = 1;    
  }
  // Fourth state: Later
  else if (state == 4){
    lcd.clear();
    lcd.setRGB(0, 50, 100);
    lcd.print("Later!");
    delay(100);
    if (digitalRead(button2) == 1)
      state = 1;    
  }
  delay(80);
  Serial.println(digitalRead(sensor)); 
}



