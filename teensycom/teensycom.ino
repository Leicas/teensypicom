/* Simple "Hello World" example.

   After uploading this to your board, use Serial Monitor
   to view the message.  When Serial is selected from the
   Tools > USB Type menu, the correct serial port must be
   selected from the Tools > Serial Port AFTER Teensy is
   running this code.  Teensy only becomes a serial device
   while this code is running!  For non-Serial types,
   the Serial port is emulated, so no port needs to be
   selected.

   This example code is in the public domain.
*/
const int ledPin = 13;
void setup()
{
  Serial.begin(9600); // USB is always 12 Mbit/sec
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  if(Serial.available() > 0) {
    digitalWrite(ledPin, HIGH);   // set the LED on
   String data = Serial.readStringUntil('\r\n');
    Serial.println(data);
    Serial.send_now();
    digitalWrite(ledPin, LOW);    // set the LED off
  }
}

