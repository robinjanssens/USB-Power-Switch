/*
  USB Power Switch

  Written by Robin Janssens (robin@robinjanssens.net)
*/

#define DEBUG 0                           // '1' enables DEBUG output
#define RELAY_PORT 12                     // pin connected to relay

char incomingByte = 0;                    // stores incoming serial data

void setup() {
  pinMode(RELAY_PORT, OUTPUT);            // initialize digital pin RELAY_PORT as an output.
  Serial.begin(9600);                     // open serial port at 9600 baud/sec
}

void loop() {
  if (Serial.available() > 0) {           // wait till serial data is received
    incomingByte = Serial.read();         // read incoming char
    #if DEBUG==1                          // if in DEBUG mode
      Serial.print(incomingByte);         // send DEBUG output repeat received data
      Serial.print(" = 0x");              // send DEBUG output add '0x' for readability
      Serial.println(incomingByte, HEX);  // send DEBUG output repeat received data in HEX
    #endif
    if(incomingByte==0x30) {              // if '0' is received
      digitalWrite(RELAY_PORT, LOW);      // switch USB power off
    } else if (incomingByte==0x31) {      // if '1' is received
      digitalWrite(RELAY_PORT, HIGH);     // switch USB power on
    } else {                              // if something else is received
                                          // ignore all other data
    }
  }
}
