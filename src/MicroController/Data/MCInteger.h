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
#include "MCData.h"

namespace Data {

  class MCInteger: public MCData {
   public:

    /* Inherit the MCData methods */
    virtual String get_key();
    virtual String to_json();
    virtual void from_json(String raw);

    /* define the accessors and mutators */
    int get_value();
    void set_value(int value);

    // The default constructors and destructor
    MCInteger();
    MCInteger(int value);
    virtual ~MCInteger();

   private:
    int value;

  };

}

#endif // MICROCONTROLLER_DATA_MCINTEGER_H_
