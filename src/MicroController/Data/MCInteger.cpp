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

/* Define the Key for the JSON Strings */
const char* MCInteger::key = "MCInteger";

/* Implement the default constructor */
MCInteger::MCInteger() {

    this->value = 0;

}

/* Implement the explicit constructor */
MCInteger::MCInteger(int value) {

    this->value = value;

}

// TODO: Implement this!
char* MCInteger::to_json() {

    return "{\"type\": \"MCInteger\", \"value\": -999}";

};

// TODO: Implement this!
void MCInteger::from_json(char* value) {

    this->value = -999

};
