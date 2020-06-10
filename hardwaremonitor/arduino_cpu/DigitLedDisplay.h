#ifndef DigitLedDisplay_h
#define DigitLedDisplay_h

#include <avr/pgmspace.h>

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

const static byte charTable_fan [] PROGMEM = {
    B01111110,B00110000,B01101101,B01111001,B00110011,B01011011,B01011111,B01110000,B01111111,B01111011
};
const static byte charTable [] PROGMEM = {
    B10000001,B11001111,B10010010,B10000110,B11001100,B10100100,B10100000,B10001111,B10000000,B10000100
};

class DigitLedDisplay
{
	private:
		int DIN_PIN;
		int CS_PIN;
		int CLK_PIN;
		int _digitLimit;
		void table(byte address, int val);	
	public:
		DigitLedDisplay(int dinPin, int csPin, int clkPin);
		void setBright(int brightness);
		void setDigitLimit(int limit);
		void printDigit(long number, byte startDigit = 0);
		void write(byte address, byte data);
		void clear();
		void on();
		void off();		
};

#endif	//DigitLedDisplay.h
