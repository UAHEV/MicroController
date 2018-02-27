//
//  MCData.h
//  MicroController
//
//  Created on 2/16/18.
//  Copyright (c) 2018 UAH Electric Vehicle Club
//  Licensed under Apache License v2.0
//
//  See README.md and LISCENSE for more details
//
//  Defines the base data type for MicroController. All
//  other data types inherit from MCData or its children

#ifndef MICROCONTROLLER_DATA_MCDATA_H_
#define MICROCONTROLLER_DATA_MCDATA_H_
#include "Arduino.h"

namespace Data {

  class MCData {
   public:
    // The key used to convert a JSON value
    // into a specific type of MCData
    static String get_key();

    // to_ and from_json(). Required for implementation
    String to_json();
    void from_json(String);

  };

}

#endif // MICROCONTROLLER_DATA_MCDATA_H_
