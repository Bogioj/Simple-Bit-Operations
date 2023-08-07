#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <bitset>

class KSP_task3 {

public:
	KSP_task3();
	~KSP_task3();

	std::vector<bool> GetBitsVector(std::string inputValue);
	std::vector<bool> GetBitsVector(uint32_t inputValue);
	void printout();

private:
	uint32_t value;
	std::vector<bool> result;
	std::vector<bool> result2;
};