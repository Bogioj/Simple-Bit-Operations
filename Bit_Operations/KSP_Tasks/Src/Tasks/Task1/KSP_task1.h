#pragma once
#include <iostream>
#include <iomanip>

class KSP_task1 {
	
public:
	KSP_task1();
	~KSP_task1();

	uint32_t GetBitsFromUint32(uint32_t inputValue, uint8_t bitOffset, uint8_t bitLength);
	void printout();

private:
	int fieldW;
	uint32_t inputValue = 0xABCDEF12;
	uint8_t bitOffset = 4;
	uint8_t bitLength = 12;
	uint32_t result = 0;
};
