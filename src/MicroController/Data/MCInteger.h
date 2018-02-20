//
//  MCInteger.h
//  MicroController
//
//  Created on 2/16/18.
//  Copyright (c) 2018 UAH Electric Vehicle Club
//  Licensed under Apache License v2.0
//
//  See README.md and LISCENSE for more details
//
//  Defines the Integer subclass for MCData

#ifndef MICROCONTROLLER_DATA_MCINTEGER_H_
#define MICROCONTROLLER_DATA_MCINTEGER_H_
#include "Arduino.h"
#include "MCData.h"

class MCInteger: MCData {
public:
  // The default constructor
  MCInteger();
  MCInteger(int value);

 private:
  int value;

};

#endif // MICROCONTROLLER_DATA_MCINTEGER_H_
