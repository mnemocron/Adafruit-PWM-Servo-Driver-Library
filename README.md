# RGBW Driver Library for PWM9685

Create objects for individual RGB(W) LED channels:

```cpp
Adafruit_RGBWDriver led = Adafruit_RGBWDriver(0, 1, 2, 3);
Adafruit_RGBDriver  led = Adafruit_RGBDriver(0, 1, 2);
```

Compatible with the `uint32_t Color` type of the Adafruit_NeoPixel Library.

```cpp
led.setColor(r, g, b);
led.setColor(r, g, b, w);
led.setColor(0x00ff0023);
```

---

# Adafruit PCA9685 PWM Servo Driver Library [![Build Status](https://travis-ci.org/adafruit/Adafruit_PWMServoDriver.svg?branch=master)](https://travis-ci.org/adafruit/Adafruit_PWMServoDriver)

This is a library for our Adafruit 16-channel PWM & Servo driver, shield or FeatherWing

<img src="https://cdn-shop.adafruit.com/970x728/815-04.jpg" height="300"/>

Pick one up today in the adafruit shop!
  * https://www.adafruit.com/products/815
  * https://www.adafruit.com/product/1411
  * https://www.adafruit.com/product/2928

These drivers use I2C to communicate, 2 pins are required to interface.

Adafruit invests time and resources providing this open source code, please support Adafruit and open-source hardware by purchasing products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries. BSD license, check license.txt for more information. 

All text above must be included in any redistribution

