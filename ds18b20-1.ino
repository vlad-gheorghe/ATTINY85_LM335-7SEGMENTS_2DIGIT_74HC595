/* 
 *  2 Digitl 7 segment display PCB board with (2) 74HC595 shift register ICs
 *  Arduino Tutorial - www.Ardumotive.com
 *  Dev: Michalis Vasilakis // Date: 31/1/2018 // Ver:1.0
 */
#include <ShiftRegister74HC595.h>
// create shift register object (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595 sr (2, PB0, PB1, PB2); 
//#define pin_sensor = PB3
#include <OneWire.h>
  #define ONE_WIRE_BUS PB3                  // DS18B20 is on P4
#include <DallasTemperature.h>
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
int number=99; // <--- Change it from 0 to 99
OneWire ds(ONE_WIRE_BUS);
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
read_sensor();
}
void read_sensor() {
    sensors.requestTemperatures();  
 int temp_val = sensors.getTempCByIndex(0);
    //temp_val = temp_val * 5.0 * 100.0 / 1024.0;
  // temp_val=100.0*(5.0*temp_val/1023-2.980);
  
  //  for (int i = 0; i<=number; i++){
    //Split number to digits:
    digit2=temp_val % 10 ;
    digit1=(temp_val / 10) % 10 ;
    //Send them to 7 segment displays
    uint8_t numberToPrint[]= {numberB[digit2],numberB[digit1]};
    sr.setAll(numberToPrint); 
    //Reset them for next time
    digit1=0;
    digit2=0;
    delay(100);
}
