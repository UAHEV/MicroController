//
//  MCData.cpp
//  MicroController
//
//  Created on 2/17/18.
//  Copyright (c) 2018 UAH Electric Vehicle Club
//  Licensed under Apache License v2.0
//
//  See README.md and LISCENSE for more details
//
//  Implements the base data type for MicroController. All
//  other data types inherit from MCData or its children
#include "MCData.h"
#include "ArduinoJson.hpp"
using namespace ArduinoJson;

using Data::MCData;

String MCData::get_key() { return "MCData"; }
