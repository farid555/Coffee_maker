#include <Arduino.h>


const int inputSwitch = 32;
const int outputRelay = 23;
const int buzzerPin = 21;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(outputRelay, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(inputSwitch, INPUT_PULLUP);
}

unsigned long coffeeRedayTime;
unsigned long buzzerOffTime;

bool isButtonPressed(){
  return digitalRead(inputSwitch) == LOW;
}

bool isRelayOn(){
  return digitalRead(outputRelay) == HIGH;
}


bool ifRelayOff(){
  return !isRelayOn();
}

void switchOnTheRelay() {
  Serial.println("Switching on the relay");
  digitalWrite(outputRelay, HIGH);
  coffeeRedayTime = millis() + 10 * 1000;  
}

void switchOffTheRelay(){
  Serial.println("Switching off the relay");
  digitalWrite(outputRelay, LOW);
}

void switchOnTheBuzzer(){
  Serial.println("Switching on the buzzer...");
  digitalWrite(buzzerPin, HIGH);
  buzzerOffTime = millis() + 5 * 1000;
  
}

bool isBuzzerOn(){
  return digitalRead(buzzerPin) == HIGH;
}

void switchOffTheBuzzer(){
  Serial.println("Switching off the buzzer...");
  digitalWrite(buzzerPin, LOW);
}



void loop() {
  // put your main code here, to run repeatedly:
if(ifRelayOff() && isButtonPressed()){
  switchOnTheRelay();
  }
    if(isRelayOn() && coffeeRedayTime < millis()){
      switchOffTheRelay();
      switchOnTheBuzzer();
  }
    if(isBuzzerOn() && buzzerOffTime < millis() ){
      switchOffTheBuzzer();
  }
}
