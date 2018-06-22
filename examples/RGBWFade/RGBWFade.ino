
#include <Wire.h>
#include <Adafruit_RGBWDriver.h>
#include <Adafruit_PWMServoDriver.h>

// PWM channels: 
// 0 = red
// 1 = green
// 2 = blue
// 3 = white
Adafruit_RGBWDriver pwm = Adafruit_RGBWDriver(0, 1, 2, 3);
// Adafruit_RGBDriver pwm = Adafruit_RGBDriver(0, 1, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel PWM test!");
  pwm.begin();
  pwm.setPWMFreq(1600);  // This is the maximum PWM frequency
  Wire.setClock(400000);
}

void loop() {
  for(uint8_t i=0; i<255; i++){
    pwm.setColor(i, 255-i, i, 255-i);
    delay(10);
  }
  for(uint8_t i=0; i<255; i++){
    pwm.setColor(255-i, i, 255-i, i);
    delay(10);
  }
}
