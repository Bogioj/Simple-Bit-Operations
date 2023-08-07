#include "KSP_task1.h"


KSP_task1::KSP_task1() {

}
KSP_task1::~KSP_task1() {

}

uint32_t KSP_task1::GetBitsFromUint32(uint32_t inputValue, uint8_t bitOffset, uint8_t bitLength)
{
	uint32_t mask = ((1u << bitLength) - 1u) << bitOffset;
	result = (inputValue & mask) >> bitOffset;
	return 0;
}

void KSP_task1::printout() {
	
	std::cout << "-----------------TASK1-----------------" << std::endl;
	std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex << result << std::endl << std::endl;
}


