#include <Joystick.h>

//H-pattern gear values
const int NEUTRAL = 0;
const int FIRST = 1;
const int SECOND = 2;
const int THIRD = 3;
const int FOURTH = 4;
const int FIFTH = 5;
const int SIXTH = 6;
const int REVERSE = 8;

//H-pattern y-axis values
const int Y_UPPER = 720;
const int Y_LOWER = 250;

//H-pattern x-axis values
const int X_LEFT = 390;
const int X_RIGHT = 700;

//Pin values
const int xPin = A0;
const int yPin = A2;
const int buttonPin = 2;

Joystick_ shifter;

int currentGear = NEUTRAL;

void setup() {
  pinMode(xPin, INPUT_PULLUP);
  pinMode(yPin, INPUT_PULLUP);
  pinMode(buttonPin, INPUT);

  shifter.begin();
}

void loop() {
  shift();
  delay(50);
}

void shift(){
  int x = analogRead(xPin);
  int y = analogRead(yPin);
  int reverse = digitalRead(buttonPin);

  int newGear = -1;

  if(y >= Y_UPPER){
    if(x <= X_LEFT) newGear = FIRST;
    if(x > X_LEFT && x < X_RIGHT) newGear = THIRD;
    if(x >= X_RIGHT) newGear = FIFTH;
  } else if(y <= Y_LOWER){
    if(x <= X_LEFT) newGear = SECOND;
    if(x > X_LEFT && x < X_RIGHT) newGear = FOURTH;
    if(x >= X_RIGHT){
      if(!reverse) newGear = SIXTH;
      if(reverse) newGear = REVERSE;
    }
  } else {
    newGear = NEUTRAL;
  }

  if(currentGear != newGear){
    currentGear = newGear;

    for(int i = 0; i < 8; i++) shifter.setButton(i, LOW);

    if(currentGear >= FIRST) shifter.setButton(currentGear - 1, HIGH);
  }
}
