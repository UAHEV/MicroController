//
//  MCConnection.h
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

#ifndef MICROCONTROLLER_CONNECTION_MCCONNECTION_H_
#define MICROCONTROLLER_CONNECTION_MCCONNECTION_H_

#include "../Data/MCData.h"

class MCConnection {
 public:
  virtual void send_data(MCData data);
  virtual MCData get_data();
  virtual bool is_connected();

  virtual ~MCConnection();

};

#endif // MICROCONTROLLER_CONNECTION_MCCONNECTION_H_
