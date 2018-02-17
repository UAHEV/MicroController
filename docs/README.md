# MicroController

`MicroController` is a framework for building Master-Slave based control systems. MicroController "projects" have 2 portions:

1. The Master Controller
    - The Master Controller uses the `MicroController` framework to define a "Master" class and a set of specialized "Input" and "Output" devices. Each input and output device extends a standard method of communication and allows the master controller object to interact with the slave devices
2. Slave Devices
    - Slave devices are divided into "Input Devices" (devicees that send data to the master) and "Output Devices" (devices that recieve actionable data from the master). Input and Output devices send data to the Master Controller by way of the `MicroControllerInputHandler.h` and `MicroControllerOutputHandler.h` headers. These single-file headers are imported into the source code for the slave devices and define a very simple API for recieving data from the Master Controller

## Demo

Suppose we want to define a very simple MicroController project with 3 devices: A Master Controller, an input switch, and an output LED. We start by writing the implentation on the Master Controller:

```cpp
// Import MCInputDevice, MCOutputDevice, and MCMasterDevice
#include "MicroController/MicroController.h"
// Import the MCBoolean
#include "MicroController/Data/MCBoolean.h"
// Import the I2CConnection
#include "MicroContoller/Connection/I2CConnection.h"

// Define a very simple "ToggleSwitch" class
class ToggleSwitch: MCInputDevice {

    // Define our connection as an I2C (Wire) connection
    I2CConnection connection;

    // Define the Constructor
    ToggleSwitch() {

        // Hard Code the address as 8
        this->connection = I2CConnection(0x08); // Wire uses hex addresses

    }

    MCBoolean get_next() {

        // Get the data from the slave with our connection
        // connection.get_data() is a template that takes the name of the class
        // you'd like to get back (a boolean in this case) and 
        MCBoolean raw_data = connection.get_data<MCBoolean>();
        return data;

    }

}

// Define a very simple "LEDIndicator" class
class LEDIndicator: MCOutputDevice {

    // Define our connection as an I2C Connection
    I2CConnection connection;

    // Define a constructor
    LEDIndicator() {

        // hard code the address as 9
        this->connection = I2CConnection(0x09);

    }

    // Define the send data function
    void send_data(MCBoolean data) {

        // connection.send_data() will automatically convert the data to it's
        // JSON value and send that to the slave
        connection.send_data(data);

    }

}

// Define a master controller class
class SimpleMasterController: MCMasterDevice {

    // Define the Input Devices this system has
    ToggleSwitch switch;

    // Define the output devices this system has
    LEDIndicator indicator;

    // Define the setup_controller() function
    void setup_controller() {
        // This function is the first thing called by MicroController. Set up
        // all your devices, variables, and other stuff here before the loop()
        // function. It is required that you implement this function!
        this->switch = ToggleSwitch();
        this->indicator = LEDIndicator();
        
        Serial.println("Setup Complete!");

    }


    // Define the loop() function
    void loop() {
        // This function is called over and over and over again from after the
        // completion of the setup_controller() function until the controller
        // loses power
        
        // Get the data from the toggle switch
        MCBoolean switch_position = this->switch.get_next();

        // Send that data to the LED
        this->indicator.send_data(switch_position);

    }


}
```

The above code implements an entire working controller where the value of a switch is sent to an LED

All that is left to do is to make the data send from the switch and be recieved by the LED. We write 2 more files:

`ToggleSwitch.cpp`
```cpp
// This is the file compiled and run on the switch controller
// It is written like any ordinary arduino sketch
#include "MicroController/Handlers/I2CInputHandler.h"
#include "Arduino.h"

// We need to set the address for this device
// This is required for the Handler to work
#define DEVICE_ADDRESS=0x09;

void setup() {

    // Use arduino's "pinmode" command to make 13 an input pin
    pinmode(13, INPUT);

}

void loop() {

    // Use Arduino's "digitalRead()" to get a value
    value = digitalRead(13);
    
    // Send the value. Every Handler File includes an "MCSend()"
    // and an "MCRecieve()" function MCSend() will send the value,
    // and the MCInputDevice that recieves it will parse it
    MCSend(value);

}
```

`LEDIndicator.cpp`
```cpp
// This is the file compiled and run on the LED Indicator
// Controller. It is written like any ordinary arduino sketch
#include "MicroController/Handlers/I2COutputHandler.h"
#include "Arduino.h"

// We need to set the address for this device
// This is required for the Handler to work
#define DEVICE_ADDRESS=0x09;

void setup() {

    // Use arduino's "pinmode" command to make 13 an output pin
    pinmode(13, OUTPUT);

}

void loop() {

    // Use I2COutputHandler's recieve function to recieve the data.
    // MCRecieve is a template that takes the type of data that the
    // output device is expecing to recieve.
    int *value = MCRecieve<int>();
    
    /*
    MAKE SURE TO:
    Check that the value is not None. If the function cannot parse the
    data recieved as the type given in MCRecieve() function, None is
    returned. If there was no data to recieve, None is returned
    */

    // Use the value with arduino's "DigitalWrite" function
    DigitalWrite(13, *value);

}
```

Each of these files gets flashed to the corresponding hardware. When connected to the same I2C Bus, MicroController will handle the rest of the communication and management for you.
