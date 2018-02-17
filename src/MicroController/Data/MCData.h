//
//  MCData.h
//  MicroController
//
//  Created by William Boyd on 2/16/18.
//  Copyright (c) 2018 UAH Electric Vehicle Club
//  Licensed under Apache License v2.0
//
//  See README.md and LISCENSE for more details
//
//  Defines the base data type for MicroController. All
//  other data types inherit from MCData or its children

#ifndef MICROCONTROLLER_DATA_MCDATA_H_
#define MICROCONTROLLER_DATA_MCDATA_H_

class MCData {
 public:
  // The hey used to convert a JSON value
  // into a specific type of MCData
  static const string key;

  // The default constructor
  MCData();
  
  // The virtual functions to_ and from_json(). Required for implementation
  string to_json() {};
  void from_json(string value) {};
      
};

#endif // MICROCONTROLLER_DATA_MCDATA_H_
