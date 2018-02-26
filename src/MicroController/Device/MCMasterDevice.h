//
//  MCMasterDevice.h
//  MicroController
//
//  Created on 2/16/18.
//  Copyright (c) 2018 UAH Electric Vehicle Club
//  Licensed under Apache License v2.0
//
//  See README.md and LISCENSE for more details
//
//  Defines the Master Device used by MicroController.
//  Must be implemented by the project developers

#ifndef MICROCONTROLLER_DEVICE_MCMASTERDEVICE_H_
#define MICROCONTROLLER_DEVICE_MCMASTERDEVICE_H_

#include "MCDevice.h"

class MCMasterDevice: public MCDevice {
 private:
  void build(void) = 0; /* MUST be implemented by the end user */
  void setup(void) { /* Do nothing by default */ };
  void loop(void) = 0; /* MUST be implented by the end user */
  void teardown(void) { /* Do nothing by default */ };
};

#endif // MICROCONTROLLER_DEVICE_MCMASTERDEVICE_H_
