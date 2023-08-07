#include "KSP_task2.h"


KSP_task2::KSP_task2() {

}
KSP_task2::~KSP_task2() {

}

uint32_t KSP_task2::GetBitsFromUint32(uint32_t inputValue, uint8_t bitOffset, uint8_t bitLength)
{
	uint32_t mask = ((1u << bitLength) - 1u) << bitOffset;
	result = (inputValue & mask) >> bitOffset;
	return 0;
}

uint32_t KSP_task2::GetBitsFromUint32(const char* inputValue, uint8_t bitOffset, uint8_t bitLength)
{
	// convert string into uint
	value = std::strtoul(inputValue, nullptr, 16);

	uint32_t mask = ((1u << bitLength) - 1u) << bitOffset;
	result = (value & mask) >> bitOffset;
	return 0;
}

void KSP_task2::printout() {

	std::cout << "-----------------TASK2-----------------" << std::endl;
	std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex << result << std::endl << std::endl;
}


