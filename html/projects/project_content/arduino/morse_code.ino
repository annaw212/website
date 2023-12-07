#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int button = 9;
int transmit = 10;
int led = 8;

String incoming = "";
int idx = 0;
int buttonStart = 0;
int buttonTime = 0;
int waitStart = 0;
int waitTime = 0;
bool transmission = false;
bool buttonPress = false;
bool spacePrinted = false;

int lcdPos = 0;

String translationChars[36]={"A","B","C","D","E","F","G","H","I","J",
                             "K","L","M","N","O","P","Q","R","S","T",
                             "U","V","W","X","Y","Z","0","1","2","3",
                             "4","5","6","7","8","9"};
String morseCode[36]={".-","-...","-.-.","-..",".","..-.","--.","....","..",
                      ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                      "...","-","..-","...-",".--","-..-","-.--","--..",
                      "-----",".----","..---","...--","....-",".....","-....",
                      "--...","---..","----."};


void setup() {
  lcd.begin(16, 2);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  pinMode(transmit, INPUT);
  digitalWrite(led, LOW);
  Serial.begin(9600);
  Serial.print("\nNew attempt\n\n\n\n\n");
  lcd.setCursor(0, 0);
}

void loop() {

  if (lcdPos % 32 == 0) {
    lcd.clear();
  }

  if (digitalRead(transmit) == HIGH) {

    if (transmission == false) {
      transmission = true;
    }

    if (digitalRead(button) == HIGH) {

      if (buttonPress == false) {
        buttonPress = true;
        buttonStart = millis();
      }

      digitalWrite(led, HIGH);

    } else {

      if (buttonPress == true) {
        buttonPress = false;
        waitStart = millis();
        buttonTime = millis() - buttonStart;

        // figure out what the character is
        if (buttonTime >= 5 && buttonTime <= 400) {
          // dot
          incoming = incoming + ".";
        }
        if (buttonTime > 400) {
          // dash
          incoming = incoming + "-";
        }
        delay(100);
      } else {
        // we are still waiting
        waitTime = millis() - waitStart;

        if (waitTime >= 1500 && waitTime < 3000) {
          // a letter has been completed
          for (int i = 0; i < 36; i++) {
            if (incoming == morseCode[i]) {
              Serial.print(translationChars[i]);
              // output to LCD here
              lcd.print(translationChars[i]);
              lcdPos++;
              break;
            }
          }
          incoming = "";
          spacePrinted = false;
        }
        if (waitTime > 3000 && spacePrinted == false) {
          Serial.print(" ");
          lcd.print(" ");
          lcdPos++;
          spacePrinted = true;
        }
      }

      if (lcdPos == 16) {
        lcd.setCursor(0, 1);
      }

      digitalWrite(led, LOW);
      delay(100);
    }
  } else {
    transmission = false;
    if (incoming != "") {
      for (int i = 0; i < 36; i++) {
        if (incoming == morseCode[i]) {
          Serial.print(translationChars[i]);
          // output to LCD here
          lcd.print(translationChars[i]);
          lcdPos++;
          if (lcdPos == 16) {
            lcd.setCursor(0, 1);
          }
        }
      }
      incoming = "";
    }
    digitalWrite(led, LOW);
  }
}
