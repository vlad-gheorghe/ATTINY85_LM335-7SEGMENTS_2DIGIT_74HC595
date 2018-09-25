/* 
 *  2 Digitl 7 segment display PCB board with (2) 74HC595 shift register ICs
 *  Arduino Tutorial - www.Ardumotive.com
 *  Dev: Michalis Vasilakis // Date: 31/1/2018 // Ver:1.0
 */
#include <ShiftRegister74HC595.h>
// create shift register object (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595 sr (2, PB0, PB1, PB2); 
//#define pin_sensor = PB3
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
  // pinMode(pin_sensor, INPUT)
  //Count from 0 to 'number' 
  //countUp();
  //Count from 'number' to 0
  //countDown();  // <--- Comment countUp and uncomment countDown
  //Blink 4 times all on and all off.
  //blink(); 
  //analogReference(INTERNAL); 
  read_sensor();
}

void loop() {
read_sensor();
}
void read_sensor() {
    int temp_val = analogRead(PB3);
    //temp_val = temp_val * 5.0 * 100.0 / 1024.0;
   temp_val=100.0*(5.0*temp_val/1023-2.980);
  
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
    delay(500);
}

/*
void countUp(){
  for (int i = 0; i<=number; i++){
    //Split number to digits:
    digit2=i % 10 ;
    digit1=(i / 10) % 10 ;
    //Send them to 7 segment displays
    uint8_t numberToPrint[]= {numberB[digit2],numberB[digit1]};
    sr.setAll(numberToPrint); 
    //Reset them for next time
    digit1=0;
    digit2=0;
    delay(1000); // Repeat every 1 sec
  }
}

void countDown(){
  for (number; number>=0; number--){
    //Split number to digits:
    digit2=number % 10 ;
    digit1=(number / 10) % 10 ;
    //Send them to 7 segment displays
    uint8_t numberToPrint[]= {numberB[digit2],numberB[digit1]};
    sr.setAll(numberToPrint); 
    //Reset them for next time
    digit1=0;
    digit2=0;
    delay(1000); // Repeat every 1 sec
  }
}

//Blink
void blink(){
  for(int i = 0; i<4; i++){
    sr.setAllLow(); // set all pins Low (off)
    delay(1000);
    sr.setAllHigh(); // set all pins High (on)
    delay(1000);
  }
}
*/
