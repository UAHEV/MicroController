//
//  MCInputDevice.h
//  MicroController
//
//  Created on 2/22/18.
//  Copyright (c) 2018 UAH Electric Vehicle Club
//  Licensed under Apache License v2.0
//
//  See README.md and LISCENSE for more details
//
//  Defines the base class for a MicroController InputDevice. All
//  other input devices will inherit from this class.

#ifndef MICROCONTROLLER_DEVICE_MCINPUTDEVICE_H_
#define MICROCONTROLLER_DEVICE_MCINPUTDEVICE_H_
#include "MCDevice.h"

class MCInputDevice: MCDevice {
 public:

  // The default constructor
  MCInputDevice();

  // The virtual function for returning data. This is required to be implemented.
  virtual void get_next() =0;

};

#endif // MICROCONTROLLER_DEVICE_MCINPUTDEVICE_H_
