#include "KSP_task7.h"

#include <cstring>
#include <stdexcept>
#include <bitset>

BitStream::BitStream(uint32_t initialSizeInBytes)
    : m_numBits(0), m_numBytes(initialSizeInBytes), m_data(m_numBytes), m_readBitPos(0)
{
    // Clear the data buffer
    //ResetData();
}

BitStream::~BitStream() {
    ResetData();
}

uint32_t BitStream::Add(uint32_t bitLength, void* dataAddr) {
    uint8_t* inputBytes = reinterpret_cast<uint8_t*>(dataAddr);
    uint32_t inputBits = bitLength;

    // Calculate the number of bytes required to store the input number of bits
    uint32_t numBytes = (inputBits + 7) / 8;

    // If the current byte buffer is not large enough to store the input number of bits,
    // resize the byte buffer to the required size
    uint32_t bitPos = m_numBits % 8;
    if (bitPos != 0) {
        // Align to byte boundary
        m_data[m_numBytes - 1] |= inputBytes[0] << bitPos;
        inputBits -= 8 - bitPos;
        inputBytes++;
    }

    if ((m_numBits + bitLength) > (m_numBytes * 8)) {
        m_data.resize(m_numBytes + numBytes);
        m_numBytes += numBytes;
    }

    // Copy the input data into the byte buffer, starting at the current bit position
    uint32_t bytePos = m_numBits / 8;
    uint32_t shift = 8 - bitPos;
    for (uint32_t i = 0; i < numBytes; i++) {
        if (inputBits >= 8) {
            m_data[bytePos++] |= (*inputBytes >> shift);
            inputBits -= 8;
            shift = 0;
            inputBytes++;
        }
        else {
            m_data[bytePos] |= (*inputBytes >> shift);
            shift += inputBits;
            inputBits = 0;
            if (shift == 8) {
                shift = 0;
                inputBytes++;
            }
        }
    }

    // Update the current bit position and return the new position
    m_numBits += bitLength;
    return m_numBits;
}


uint32_t BitStream::Get(uint32_t bitLength, void* dataAddr) {
    uint32_t startPos = m_readBitPos;
    uint8_t* dest = reinterpret_cast<uint8_t*>(dataAddr);

    // Calculate the maximum number of bits that can be read
    uint32_t maxBits = m_numBits - startPos;
    uint32_t numBits = std::min(bitLength, maxBits);

    for (uint32_t i = 0; i < numBits; i++) {
        uint32_t bitPos = startPos + i;
        uint32_t bytePos = bitPos / 8;
        uint32_t bitOffset = bitPos % 8;
        dest[i / 8] |= ((m_data[bytePos] >> bitOffset) & 1) << (i % 8);
    }

    m_readBitPos += numBits;
    return numBits;
}

uint32_t BitStream::GetBitLength() const {
    return m_numBits;
}

/*uint32_t BitStream::GetData(void* addr, uint32_t maxBitLength) const {
    uint32_t bitLength = std::min(maxBitLength, GetBitLength());
    uint8_t* dest = static_cast<uint8_t*>(addr);
    uint32_t byteLength = (bitLength + 7) / 8;

    // Copy the data to the destination buffer
    for (uint32_t i = 0; i < byteLength; i++)
    {
        dest[i] = m_data[i];
    }

    // Clear the remaining bits in the last byte if necessary
    if (bitLength % 8 != 0)
    {
        dest[byteLength - 1] &= (1 << (bitLength % 8)) - 1;
    }

    return bitLength;
}*/
void BitStream::GetData(void* dataAddr, uint32_t numBits) const {
    uint8_t* dest = reinterpret_cast<uint8_t*>(dataAddr);

    for (uint32_t i = 0; i < (numBits + 7) / 8; i++) {
        dest[i] = m_data[i];
    }
}


void BitStream::ResetData(){
    m_numBits = 0;
    m_numBytes = 0;
    m_writeBitPos = 0;
    m_readBitPos = 0;
    m_data.clear();
}



