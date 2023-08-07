#include "KSP_task3.h"


KSP_task3::KSP_task3() {

}
KSP_task3::~KSP_task3() {

}

std::vector<bool> KSP_task3::GetBitsVector(std::string inputValue) {

	//convert string into uint
	value = std::stoul(inputValue, nullptr, 16);

	//extract individual bits
	std::bitset <32> bits(value);

	//cinvert bitset to bools
	std::vector<bool> result;
	for (int i = 0; i < 32; i++) {
		result.push_back(bits[i]);
	}
	return result;
}

std::vector<bool> KSP_task3::GetBitsVector(uint32_t inputValue) {

	//extract individual bits
	std::bitset <32> bits(inputValue);

	//convert bitset to bools
	for (int i = 0; i < 32; i++) {
		result.push_back(bits[i]);
	}
	return result;
}

void KSP_task3::printout() {

	std::cout << "-----------------TASK3-----------------" << std::endl;
	for (bool b : result) {
		std::cout << b << "  ";
	}
	std::cout << std::endl << std::endl;
}


