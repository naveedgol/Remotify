#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>


#define LED RED_LED
boolean stringComplete = false;
char inputText[100];
void setup() {
  // put your setup code here, to run once:
  OrbitOledInit();
  OrbitOledClear();
  OrbitOledClearBuffer();
  OrbitOledSetDrawMode(modOledSet);
  Serial.begin(9600);
  Serial.flush();
  pinMode(LED, OUTPUT);   
}

void loop() {
  Serial.println("0");
  if(stringComplete){
    OrbitOledClear();
    OrbitOledClearBuffer();
    OrbitOledMoveTo(0, 0);
    OrbitOledDrawString(inputText);
    OrbitOledUpdate();
    memset(inputText,0,100);
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    Serial.readBytesUntil('\n',inputText, 1000);
    stringComplete = true;
  }
}
