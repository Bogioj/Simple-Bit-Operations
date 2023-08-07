#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

class KSP_task2 {

public:
	KSP_task2();
	~KSP_task2();

	uint32_t GetBitsFromUint32(uint32_t inputValue, uint8_t bitOffset, uint8_t bitLength);
	uint32_t GetBitsFromUint32(const char* inputValue, uint8_t bitOffset, uint8_t bitLength);
	void printout();

private:
	int fieldW;
	uint32_t value;
	uint32_t inputValue = 0xABCDEF12;
	uint8_t bitOffset = 4;
	uint8_t bitLength = 12;
	uint32_t result = 0;
};
