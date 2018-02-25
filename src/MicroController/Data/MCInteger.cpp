//
//  MCInteger.cpp
//  MicroController
//
//  Created on 2/16/18.
//  Copyright (c) 2018 UAH Electric Vehicle Club
//  Licensed under Apache License v2.0
//
//  See README.md and LISCENSE for more details
//
//  Implementation for the Integer subclass for MCData

#include "MCInteger.h"
#include "ArduinoJson.hpp"


/* Define the Key for the JSON Strings */
String MCInteger::get_key() { return "MCInteger"; }

/* Implement the default constructor */
MCInteger::MCInteger() {
  this->value = 0;
}

/* Implement the explicit constructor */
MCInteger::MCInteger(int value) {
  this->value = value;
}

/* Implement the accessors and mutators */
int MCInteger::get_value() {

  return this->value;

}

void MCInteger::set_value(int value) {

  this->value = value;

}

/* Implement the destructor */
MCInteger::~MCInteger() {}

// TODO: Implement this!
String MCInteger::to_json() {

  ArduinoJson::StaticJsonBuffer<200> json;
  ArduinoJson::JsonObject& root = json.createObject();
  root["type"] = MCInteger::get_key();
  root["value"] = this->value;

  String return_value;
  root.printTo(return_value);

  return return_value;

};

// TODO: Implement this!
void MCInteger::from_json(String raw) {
  ArduinoJson::StaticJsonBuffer<200> json;
  ArduinoJson::JsonObject& root = json.parseObject(raw);

  /* Check if there was an error */
  if (root.success() == false) {
    // TODO: Handle this error
  }
  else {
    int value = root["value"];
    this->value= value;
  }

};
