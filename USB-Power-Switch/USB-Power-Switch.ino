/*
  USB Power Switch

  Written by Robin Janssens (robin@robinjanssens.net)
*/

#define RELAY_PORT 12

void setup() {
  pinMode(RELAY_PORT, OUTPUT);      // initialize digital pin RELAY_PORT as an output.
}

void loop() {
  digitalWrite(RELAY_PORT, HIGH);   // switch usb port on
  delay(1000);                      // wait for a second
  digitalWrite(RELAY_PORT, LOW);    // switch usb port off
  delay(1000);                      // wait for a second
}
