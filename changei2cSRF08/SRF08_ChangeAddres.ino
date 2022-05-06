/*
Generic example for the SRF modules 02, 08, 10 and 235.
Only the SRF08 uses the light saensor so when any other
range finder is used with this code the light reading will
be a constant value.
*/

#include <Wire.h>
#include <SoftwareSerial.h>


#define OLD_ADDRESS 0x70  // Old Address of the SRF08 0xE0 -> 0x70 for 7 bit addresses
#define NEW_ADDRESS 0xE6  // New Address of the SRF08 0xE2 -> 0x71 for 7 bit addresses

void setup(){

Wire.begin();
delay(100);
// Waits to make sure everything is powered up before sending or receiving data

/*
change address from 0XE0 to 0XE2 7 bit address shifts adresses 1 bit right 0xE0 -> 0x70, 0xE2 -> 0x71
change address from 0XE0 to 0XE4 7 bit address shifts adresses 1 bit right 0xE0 -> 0x70, 0xE4 -> 0x72
change address from 0XE0 to 0XE6 7 bit address shifts adresses 1 bit right 0xE0 -> 0x70, 0xE6 -> 0x73
*/

changeAddress(OLD_ADDRESS, NEW_ADDRESS);

delay(1000); // Wait for change to be complete

Serial.begin(9600);

}

void loop(){

Serial.print("new SRF08 address = ");
Serial.println(NEW_ADDRESS, HEX); // Display new address

delay(1000); // Wait before looping
}

// The following code changes the address of a Devantech Ultrasonic Range Finder (SRF10 or SRF08)
// usage: changeAddress(0x70, 0x71);

void changeAddress(byte oldAddress, byte newAddress)
{
Wire.beginTransmission(oldAddress);
Wire.write(byte(0x00));
Wire.write(byte(0xA0));
Wire.endTransmission();

Wire.beginTransmission(oldAddress);
Wire.write(byte(0x00));
Wire.write(byte(0xAA));
Wire.endTransmission();

Wire.beginTransmission(oldAddress);
Wire.write(byte(0x00));
Wire.write(byte(0xA5));
Wire.endTransmission();

Wire.beginTransmission(oldAddress);
Wire.write(byte(0x00));
Wire.write(newAddress);
Wire.endTransmission();
}
