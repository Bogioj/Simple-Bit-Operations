#pragma once
#include <iostream>
#include <vector>

class BitStream {

public:
	BitStream(uint32_t initialSizeInBytes);
	~BitStream();

	uint32_t Add(uint32_t bitLength, void* dataAddr);
	uint32_t Get(uint32_t bitLength, void* dataAddr);
	uint32_t GetBitLength() const;
	void GetData(void* dataAddr, uint32_t numBits) const;
	void ResetData();

private:
	uint32_t m_numBits;
	uint32_t m_numBytes;
	std::vector<uint8_t> m_data;
	uint32_t m_readBitPos;
	uint32_t m_writeBitPos;
};