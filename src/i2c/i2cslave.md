```
// Do not remove the include below
#include "TestProgram.h"

#include "MicroController.h"
#include "Wire.h"
#include "I2CANYthing.h"
//void receiveEvent (int howMany);
void requestEvent();
const byte MY_ADDRESS = 42;

volatile boolean haveData = false;
volatile float fnum;
volatile long foo;
bool flag = false;
//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here

	Serial.begin(9600);
	Serial.println("Hello world!");

	MCInteger number = MCInteger(5);
	Serial.println(number.to_json());
	Wire.begin (MY_ADDRESS);
	Serial.begin (115200);
	//Wire.onReceive (receiveEvent);
	Wire.onRequest(requestEvent); // register event
}

// The loop function is called in an endless loop
void loop()
{
  if (haveData)
    {
    Serial.print ("Received fnum = ");
    Serial.println (fnum);
    Serial.print ("Received foo = ");
    Serial.println (foo);
    haveData = false;
    }  // end if haveData

}  // end of loop

// called by interrupt service routine when incoming data arrives
/*void receiveEvent (int howMany)
 {
 if (howMany >= (sizeof fnum) + (sizeof foo))
   {
   I2C_readAnything (fnum);
   I2C_readAnything (foo);
   haveData = true;
   }  // end if have enough data
 }  // end of receiveEvent*/
void requestEvent()
{
	String message="hello";
if (flag)
{
	I2C_writeAnything(message);
}
else
{
	I2C_writeAnything(message.length());
}
}

```
