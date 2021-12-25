#include <Joystick.h>

//H-pattern gear values
#define NEUTRAL 0
#define FIRST 1
#define SECOND 2
#define THIRD 3
#define FOURTH 4
#define FIFTH 5
#define SIXTH 6
#define REVERSE 8

//H-pattern y-axis values
#define Y_UPPER 720
#define Y_LOWER 250

//H-pattern x-axis values
#define X_LEFT 390
#define X_RIGHT 700

//Pin values
#define xPin A0
#define yPin A2
#define buttonPin 2

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
