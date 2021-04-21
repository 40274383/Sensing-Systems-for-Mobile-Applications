int ledCorrect = 7;
int ledIncorrect = 8;
int ledSkipped = 6;
#include "application.h"
#include "LiquidCrystal/LiquidCrystal.h"
LiquidCrystal lcd(D0, D1, D2, D3, D4, D5);

void setup()
{

  
   pinMode(ledCorrect, OUTPUT);
   pinMode(ledIncorrect, OUTPUT);
   pinMode(ledSkipped, OUTPUT);

   Particle.function("green",ledGreen);
   Particle.function("red",ledRed);
   Particle.function("yellow",ledClear);
   
   digitalWrite(ledCorrect, LOW);
   digitalWrite(ledIncorrect, LOW);
   digitalWrite(ledSkipped, LOW);

   lcd.begin(16,2);
}

void loop()
{
   
}


int ledGreen(String command) {
    if (command=="on") {
        digitalWrite(ledCorrect,HIGH);
        lcd.begin(16,2);
        lcd.setCursor(0,0);
        // Print a message to the LCD.
        lcd.print("Correct!");
        delay(1000);
        digitalWrite(ledCorrect,LOW);
        lcd.print("");
        return 1;
    }
    else if (command=="off") {
        digitalWrite(ledCorrect,LOW);
        return 0;
    }
    else {
        return -1;
    }
}

int ledRed(String command) {
    if (command=="on") {
        digitalWrite(ledIncorrect,HIGH);
        lcd.begin(16,2);
        lcd.setCursor(0,0);
        // Print a message to the LCD.
        lcd.print("Incorrect!");
        delay(1000);
        digitalWrite(ledIncorrect,LOW);
        lcd.print("");
        return 1;
    }
    else if (command=="off") {
        digitalWrite(ledIncorrect,LOW);
        return 0;
    }
    else {
        return -1;
    }
}

int ledClear(String command) {
    if (command=="on") {
        digitalWrite(ledSkipped,HIGH);
        lcd.begin(16,2);
        lcd.setCursor(0,0);
        // Print a message to the LCD.
        lcd.print("Skipped!");
        delay(1000);
        digitalWrite(ledSkipped,LOW);
        lcd.print("");
        return 1;
    }
    else if (command=="off") {
        digitalWrite(ledSkipped,LOW);
        return 0;
    }
    else {
        return -1;
    }
}