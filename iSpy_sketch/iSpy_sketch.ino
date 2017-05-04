#include <Servo.h> // Import the library

int redLedPin = 2;
Servo servoPan, servoTilt; // Create servo object
String data = ""; // Store incoming commands (buffer)

void setup() {
    // Setup servos on PWM capable pins
    servoPan.attach(9); 
    servoTilt.attach(3);
    pinMode(redLedPin, OUTPUT);
    digitalWrite(redLedPin, HIGH);
    Serial.begin(9600); // Start serial at 9600 bps (speed)
}

void loop() {
    while (Serial.available() > 0)
    {
      digitalWrite(redLedPin, LOW);
      
        // If there is data
        char singleChar = Serial.read(); // Read each character

        if (singleChar == 'P') {
            // Move pan servo
            servoPan.write(data.toInt());
            data = ""; // Clear buffer
            digitalWrite(redLedPin, HIGH);
        }
        else if (singleChar == 'T') {
            // Move tilt servo
            servoTilt.write(data.toInt());
            data = ""; // Clear buffer
            digitalWrite(redLedPin, HIGH);
        }
        else {
            data += singleChar; // Append new data
        }
    }
}
