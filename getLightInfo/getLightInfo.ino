/*
Generic example for the SRF modules 02, 08, 10 and 235.
Only the SRF08 uses the light saensor so when any other 
range finder is used with this code the light reading will 
be a constant value. 
*/

#include <Wire.h>

#define LCD_RX              0x02                                   // Software serial pin for rx
#define LCD_TX              0x03                                   // Software serial pin for tx
#define SRF_ADDRESS         0x73                                   // Address of the SRF08
#define CMD                 (byte)0x00                             // Command byte, values of 0 being sent with write have to be masked as a byte to stop them being misinterpreted as NULL this is a bug with arduino 1.0
#define LIGHTBYTE           0x01                                   // Byte to read light sensor
#define RANGEBYTE           0x02                                   // Byte for start of ranging data

byte highByte = 0x00;                             // Stores high byte from ranging
byte lowByte = 0x00;                              // Stored low byte from ranging

void setup(){
  Wire.begin();                               
  delay(100);                                     // Waits to make sure everything is powered up before sending or receiving data    
}

void loop(){
 
  int lightData = getLight();                     // Call function to get light reading and store in lightData
  Serial.print("light = ");
  Serial.println(lightData, DEC);                   // Display lightData  
 delay(100);     // Wait before looping

}


int getLight(){                                    // Function to get light reading
  
  Wire.beginTransmission(SRF_ADDRESS);
  Wire.write(LIGHTBYTE);                           // Call register to get light reading
  Wire.endTransmission();
  
  Wire.requestFrom(SRF_ADDRESS, 1);                // Request 1 byte
  while(Wire.available() < 0);                     // While byte available
  int lightRead = Wire.read();                     // Get light reading
    
  return(lightRead);                               // Returns lightRead
  
}

