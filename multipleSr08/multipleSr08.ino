/*
Generic example for the SRF modules 08.
On this code is use 4 SRF08 with already different addres
And using arduino Uno with one terminal i2c
You might have to change SRF08 addres  before using this 
*/

#include <Wire.h>

#define SRF_ADDRESS1         0x70                                   // Address of the SRF08
#define SRF_ADDRESS2         0x71                                   // Address of the SRF08
#define SRF_ADDRESS3         0x72                                   // Address of the SRF08
#define SRF_ADDRESS4         0x73                                   // Address of the SRF08
#define CMD                 (byte)0x00                             // Command byte, values of 0 being sent with write have to be masked as a byte to stop them being misinterpreted as NULL this is a bug with arduino 1.0
#define LIGHTBYTE           0x01                                   // Byte to read light sensor
#define RANGEBYTE           0x02                                   // Byte for start of ranging data


byte highByte = 0x00;                             // Stores high byte from ranging
byte lowByte = 0x00;                              // Stored low byte from ranging
int reading = 0;

void setup() {
  Wire.begin();                // join i2c bus (address optional for master)
  Serial.begin(9600);          // start serial communication at 9600bps
}

void loop() {
  int range = 0; 
  
  Wire.beginTransmission(SRF_ADDRESS1);             // Start communticating with SRF08
  Wire.write(CMD);                                 // Send Command Byte
  Wire.write(0x51);                                // Send 0x51 to start a ranging
  Wire.endTransmission();
  
  delay(100);                                      // Wait for ranging to be complete
  
  Wire.beginTransmission(SRF_ADDRESS1);             // start communicating with SRFmodule
  Wire.write(RANGEBYTE);                           // Call the register for start of ranging data
  Wire.endTransmission();
  
  Wire.requestFrom(SRF_ADDRESS1, 2);                // Request 2 bytes from SRF module
  while(Wire.available() < 2);                     // Wait for data to arrive
  highByte = Wire.read();                          // Get high byte
  lowByte = Wire.read();                           // Get low byte

  range = (highByte << 8) + lowByte;               // Put them together
  
  
  int reading1 = range;
  Serial.print("depan = ");
  Serial.println(reading1);
  
  delay(50);

  
  int range2 = 0; 
  
  Wire.beginTransmission(SRF_ADDRESS2);             // Start communticating with SRF08
  Wire.write(CMD);                                 // Send Command Byte
  Wire.write(0x51);                                // Send 0x51 to start a ranging
  Wire.endTransmission();
  
  delay(100);                                      // Wait for ranging to be complete
  
  Wire.beginTransmission(SRF_ADDRESS2);             // start communicating with SRFmodule
  Wire.write(RANGEBYTE);                           // Call the register for start of ranging data
  Wire.endTransmission();
  
  Wire.requestFrom(SRF_ADDRESS2, 2);                // Request 2 bytes from SRF module
  while(Wire.available() < 2);                     // Wait for data to arrive
  highByte = Wire.read();                          // Get high byte
  lowByte = Wire.read();                           // Get low byte

  range2 = (highByte << 8) + lowByte;               // Put them together
  
  int reading2 =range2;
  Serial.print("kanan = ");
  Serial.println(reading2);
  

  int range3 = 0; 
  
  Wire.beginTransmission(SRF_ADDRESS3);             // Start communticating with SRF08
  Wire.write(CMD);                                 // Send Command Byte
  Wire.write(0x51);                                // Send 0x51 to start a ranging
  Wire.endTransmission();
  
  delay(100);                                      // Wait for ranging to be complete
  
  Wire.beginTransmission(SRF_ADDRESS3);             // start communicating with SRFmodule
  Wire.write(RANGEBYTE);                           // Call the register for start of ranging data
  Wire.endTransmission();
  
  Wire.requestFrom(SRF_ADDRESS3, 2);                // Request 2 bytes from SRF module
  while(Wire.available() < 2);                     // Wait for data to arrive
  highByte = Wire.read();                          // Get high byte
  lowByte = Wire.read();                           // Get low byte

  range3 = (highByte << 8) + lowByte;               // Put them together
  
  int reading3 =range3;
  Serial.print("belakang = ");
  Serial.println(reading3);


  int range4 = 0; 
  
  Wire.beginTransmission(SRF_ADDRESS4);             // Start communticating with SRF08
  Wire.write(CMD);                                 // Send Command Byte
  Wire.write(0x51);                                // Send 0x51 to start a ranging
  Wire.endTransmission();
  
  delay(100);                                      // Wait for ranging to be complete
  
  Wire.beginTransmission(SRF_ADDRESS4);             // start communicating with SRFmodule
  Wire.write(RANGEBYTE);                           // Call the register for start of ranging data
  Wire.endTransmission();
  
  Wire.requestFrom(SRF_ADDRESS4, 2);                // Request 2 bytes from SRF module
  while(Wire.available() < 2);                     // Wait for data to arrive
  highByte = Wire.read();                          // Get high byte
  lowByte = Wire.read();                           // Get low byte

  range4 = (highByte << 8) + lowByte;               // Put them together
  
  int reading4 =range4;
  Serial.print("kiri = ");
  Serial.println(reading4);
  Serial.println("---------------------------");

  delay(100)
}
