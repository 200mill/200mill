#pragma region "Includes"

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#pragma endregion

LiquidCrystal_I2C lcd(0x27, 16, 2);

#pragma region "defines"
#define echo 11
#define trig 10

//DC_motor
//1
//후륜
// test : left
#define ENA // ENA를 사용해야할 이유를 발견하지 못함
#define IN11 13
#define IN12 12


//2
// test : right
#define ENA2 // 여기도 마찬가지
#define IN21 8
#define IN22 7

#pragma endregion

void setup() {
    Serial.begin(9600);

    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);

    pinMode(IN11, OUTPUT);
    pinMode(IN12, OUTPUT);

    pinMode(IN21, OUTPUT);
    pinMode(IN22, OUTPUT);

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("");

}

void loop() {
    digitalWrite(IN11, HIGH);
    digitalWrite(IN12, LOW);
    digitalWrite(IN21, LOW);
    digitalWrite(IN22, HIGH);

    motorControl();

    char dir = Serial.read();
    keyboardcontrol(dir);

    
}

void keyboardcontrol(char direction)
{
  switch(direction)
  {
    case '1':
      Serial.println("Foward");
      digitalWrite(IN11, HIGH);
      digitalWrite(IN12, LOW);

      digitalWrite(IN21, HIGH);
      digitalWrite(IN22, LOW);
      break;
    case '2':
      Serial.println("backward");
      digitalWrite(IN11, LOW);
      digitalWrite(IN12, HIGH);
      digitalWrite(IN21, LOW);
      digitalWrite(IN22, HIGH);
      break;
    case '3':
      Serial.println("Pause");
      digitalWrite(IN11, LOW);
      digitalWrite(IN12, LOW);
      digitalWrite(IN21, LOW);
      digitalWrite(IN22, LOW);
      break;
    default:
      break;
  }
  motorControl();
  Serial.println("return");
}


void motorControl()
{
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    
    unsigned long duration = pulseIn(echo, HIGH);
    float distance = ((float)(340*duration)/10000)/2;
    Serial.println("Report Created");
    Serial.print("distance(cm) = ");
    Serial.println(distance);
    if(distance <=15)
    {
        //stop
        digitalWrite(IN11, LOW);
        digitalWrite(IN12, LOW);
        digitalWrite(IN21, LOW);
        digitalWrite(IN22, LOW);

        delay(100);

        digitalWrite(IN11, LOW);
        digitalWrite(IN12, HIGH);
        digitalWrite(IN21, LOW);
        digitalWrite(IN22, HIGH);
        delay(200); 

        digitalWrite(IN11, HIGH);
        digitalWrite(IN12, LOW);

        delay(500);
        
    }
}



