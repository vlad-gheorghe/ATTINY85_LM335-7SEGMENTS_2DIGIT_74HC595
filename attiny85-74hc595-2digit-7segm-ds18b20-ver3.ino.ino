
/* 
 *  2 Digitl 7 segment display PCB board with (2) 74HC595 shift register ICs
 *  Arduino Tutorial - www.Ardumotive.com
 *  Dev: Michalis Vasilakis // Date: 31/1/2018 // Ver:1.0
 */
#include <ShiftRegister74HC595.h>
#include <OneWire.h>
#include <DallasTemperature.h>
// create shift register object (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595 sr (2, PB2, PB1, PB0); 

#define ONE_WIRE_BUS PB3
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
int number=99; // <--- Change it from 0 to 99

int value,digit1,digit2,digit3,digit4; 
uint8_t  numberB[] = {B11000000, //0
                      B11111001, //1 
                      B10100100, //2
                      B10110000, //3 
                      B10011001, //4
                      B10010010, //5
                      B10000011, //6
                      B11111000, //7
                      B10000000, //8
                      B10011000 //9
                     };
                        
void setup() {
  
 sensors.begin();

}

void loop() {
  sensors.requestTemperatures();  
 int temp = sensors.getTempCByIndex(0);
 digit2=temp % 10 ;
    digit1=(temp / 10) % 10 ;
    uint8_t numberToPrint[]= {numberB[digit2],numberB[digit1]};
    sr.setAll(numberToPrint); 
    //Reset them for next time
    digit1=0;
    digit2=0;
  //  delay(50);
}

