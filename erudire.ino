#include <LiquidCrystal.h> // include LiquidCrystal library
#include <stdlib.h>        // include stdlib library
#include <string.h>        // include string library

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // define LCD pins
const int ledPin = 13;                                      // led no pino 13
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                  // create LCD object

const int buttonPin = 6; // button pin
int incomingByte, x, y;

void setup()
{
    lcd.begin(16, 2);
    Serial.begin(9600);
    pinMode(buttonPin, INPUT); // button pin is an input
    pinMode(ledPin, OUTPUT);   // led pin is an output
}

void loop()
{
    if (Serial.available() > 0)
    {

        incomingByte = Serial.read();

        lcd.print(char(incomingByte));
        x = x + 1;
        y = y + 1;
        if (x > 15)
        {
            lcd.setCursor(0, 1);
            x = 0;
        }
        if (y > 31)
        {
            lcd.setCursor(0, 0);
            y = 0;
            x = 0;
        }
    }

    int buttonState = digitalRead(buttonPin); // read current button state

    if (buttonState == HIGH) // if button is pressed
    {
        digitalWrite(ledPin, HIGH); // ledPin on
        int r = random(0, 5);       // generate a random number between 0 and 4
        if (r == 0)
        {                        // if number is 0
            lcd.clear();         // clear display
            lcd.setCursor(0, 0); // move cursor to first column of first line
            lcd.print("Yes");    // display "Yes" on display
        }
        if (r == 1)
        {                        // if number is 1
            lcd.clear();         // clear display
            lcd.setCursor(0, 0); // move cursor to first column of first line
            lcd.print("No");    // display "No" on display
        }
        if (r == 2)
        {                        // if number is 2
            lcd.clear();         // clear display
            lcd.setCursor(0, 0); // move cursor to first column of first line
            lcd.print("Maybe"); // display "Maybe" on display
        }
        if (r == 3)
        {                                 // if number is 3
            lcd.clear();                  // clear display
            lcd.setCursor(0, 0);          // move cursor to first column of first line
            lcd.print("Who knows!"); // display "Who knows!" on display
        }
        if (r == 4)
        {                          // if number is 4
            lcd.clear();           // clear display
            lcd.setCursor(0, 0);   // move cursor to first column of first line
            lcd.print("Obvious!!!"); // display "Obvious!!!" on display
        }
    }
    else
    {                              // if button is not pressed
        digitalWrite(ledPin, LOW); // ledPin off
    }
}
