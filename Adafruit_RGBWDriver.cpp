/*************************************************** 
  This is a library for our Adafruit 16-channel PWM & Servo driver

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include "Adafruit_RGBWDriver.h"
#include "Adafruit_PWMServoDriver.h"
#include <Wire.h>

void Adafruit_RGBDriver::setChannels(uint8_t r, uint8_t g, uint8_t b){
  this->ch_R = r;
  this->ch_G = g;
  this->ch_B = b;
}

Adafruit_RGBDriver::Adafruit_RGBDriver(uint8_t r, uint8_t g, uint8_t b):Adafruit_PWMServoDriver(){
  this->setChannels(r, g, b);
};
Adafruit_RGBDriver::Adafruit_RGBDriver(uint8_t addr, uint8_t r, uint8_t g, uint8_t b):Adafruit_PWMServoDriver(addr){
  this->setChannels(r, g, b);
};
Adafruit_RGBDriver::Adafruit_RGBDriver(TwoWire *i2c, uint8_t addr, uint8_t r, uint8_t g, uint8_t b):Adafruit_PWMServoDriver(i2c, addr){
  this->setChannels(r, g, b);
};
  
void Adafruit_RGBDriver::begin(void){
	this->Adafruit_PWMServoDriver::begin();
}
void Adafruit_RGBDriver::reset(void){
	this->Adafruit_PWMServoDriver::reset();
}
void Adafruit_RGBDriver::setPWMFreq(float freq){
	this->Adafruit_PWMServoDriver::setPWMFreq(freq);
}

void Adafruit_RGBDriver::setColor(uint32_t c){
  uint8_t r = (uint8_t)(c >> 16);
  uint8_t g = (uint8_t)(c >>  8);
  uint8_t b = (uint8_t) c;
  this->setColor(r, g, b);
}

void Adafruit_RGBDriver::setColor(uint8_t r, uint8_t g, uint8_t b){
  this->setPWM(this->ch_R, 0, (r*16)  );
  this->setPWM(this->ch_G, 0, (g*16)  );
  this->setPWM(this->ch_B, 0, (b*16)  );
}

// Convert separate R,G,B into packed 32-bit RGB color.
// Packed format is always RGB, regardless of LED strand color order.
uint32_t Adafruit_RGBDriver::Color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

/***************************************************************/

void Adafruit_RGBWDriver::setChannels(uint8_t r, uint8_t g, uint8_t b, uint8_t w){
  this->ch_R = r;
  this->ch_G = g;
  this->ch_B = b;
  this->ch_W = w;
}

Adafruit_RGBWDriver::Adafruit_RGBWDriver(uint8_t r, uint8_t g, uint8_t b, uint8_t w):Adafruit_PWMServoDriver(){
  this->setChannels(r, g, b, w);
};
Adafruit_RGBWDriver::Adafruit_RGBWDriver(uint8_t addr, uint8_t r, uint8_t g, uint8_t b, uint8_t w):Adafruit_PWMServoDriver(addr){
  this->setChannels(r, g, b, w);
};
Adafruit_RGBWDriver::Adafruit_RGBWDriver(TwoWire *i2c, uint8_t addr, uint8_t r, uint8_t g, uint8_t b, uint8_t w):Adafruit_PWMServoDriver(i2c, addr){
  this->setChannels(r, g, b, w);
};
  
void Adafruit_RGBWDriver::begin(void){
	this->Adafruit_PWMServoDriver::begin();
}
void Adafruit_RGBWDriver::reset(void){
	this->Adafruit_PWMServoDriver::reset();
}
void Adafruit_RGBWDriver::setPWMFreq(float freq){
	this->Adafruit_PWMServoDriver::setPWMFreq(freq);
}

void Adafruit_RGBWDriver::setColor(uint32_t c){
  uint8_t w = (uint8_t)(c >> 24);
  uint8_t r = (uint8_t)(c >> 16);
  uint8_t g = (uint8_t)(c >>  8);
  uint8_t b = (uint8_t) c;
  this->setColor(r, g, b, w);
}

void Adafruit_RGBWDriver::setColor(uint8_t r, uint8_t g, uint8_t b){
  this->setPWM(this->ch_R, 0, (r*16)  );
  this->setPWM(this->ch_G, 0, (g*16)  );
  this->setPWM(this->ch_B, 0, (b*16)  );
}

void Adafruit_RGBWDriver::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t w){
  this->setPWM(this->ch_R, 0, (r*16)  );
  this->setPWM(this->ch_G, 0, (g*16)  );
  this->setPWM(this->ch_B, 0, (b*16)  );
  this->setPWM(this->ch_W, 0, (w*16)  );
}

// Convert separate R,G,B into packed 32-bit RGB color.
// Packed format is always RGB, regardless of LED strand color order.
uint32_t Adafruit_RGBWDriver::Color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

// Convert separate R,G,B,W into packed 32-bit WRGB color.
// Packed format is always WRGB, regardless of LED strand color order.
uint32_t Adafruit_RGBWDriver::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
  return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}




