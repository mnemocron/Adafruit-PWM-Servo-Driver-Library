/*************************************************** 
  This is a library for our Adafruit 16-channel PWM & Servo driver

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#ifndef _ADAFRUIT_RGBDriver_H
#define _ADAFRUIT_RGBDriver_H

#include "Adafruit_PWMServoDriver.h"
#include <Wire.h>

class Adafruit_RGBDriver : public Adafruit_PWMServoDriver {
 private:
  uint8_t ch_R;
  uint8_t ch_G;
  uint8_t ch_B;

  void setChannels(uint8_t r, uint8_t g, uint8_t b);
  
 public:
  void begin(void);
  void reset(void);
  void setPWMFreq(float freq);
  Adafruit_RGBDriver(uint8_t r, uint8_t g, uint8_t b);
  Adafruit_RGBDriver(uint8_t addr, uint8_t r, uint8_t g, uint8_t b);
  Adafruit_RGBDriver(TwoWire *i2c, uint8_t addr, uint8_t r, uint8_t g, uint8_t b);
  void setColor(uint32_t c);
  void setColor(uint8_t r, uint8_t g, uint8_t b);
  uint32_t Color(uint8_t r, uint8_t g, uint8_t b);
};

class Adafruit_RGBWDriver : public Adafruit_PWMServoDriver {
 private:
  uint8_t ch_R;
  uint8_t ch_G;
  uint8_t ch_B;
  uint8_t ch_W;

  void setChannels(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
  
 public:
  void begin(void);
  void reset(void);
  void setPWMFreq(float freq);
  Adafruit_RGBWDriver(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
  Adafruit_RGBWDriver(uint8_t addr, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
  Adafruit_RGBWDriver(TwoWire *i2c, uint8_t addr, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
  void setColor(uint32_t c);
  void setColor(uint8_t r, uint8_t g, uint8_t b);
  void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
  uint32_t Color(uint8_t r, uint8_t g, uint8_t b);
  uint32_t Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
};

#endif





  