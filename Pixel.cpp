// Pixel.cpp
// Authors: Hunter King, Joe Story

#include <iostream>
#include <iomanip>
#include <array>
#include "Pixel.h"
#include "Tools.h"

Pixel::Pixel(){
}

uint8_t * Pixel::getByteColor(uint16_t byte){
    uint8_t byte1 = (byte & 0xF0) >> 8; // grab high order byte out of the 2
    uint8_t byte2 = byte & 0x0F;        // grab low order byte
    uint8_t mask = 0x01;

    std::cout << "our byte is: " << std::hex << byte << std::endl;
    std::cout << "our byte1 is: " << std::hex << static_cast<int>(byte1) << std::endl;
    std::cout << "our byte2 is: " << std::hex << static_cast<int>(byte2) << std::endl;

                                                  for (int i = 0; i < 8; i++)
    {
        if (byte1 & (mask << i)) miniPix[8-i] += 1; // if byte 1's bit is on
        if (byte2 & (mask << i)) miniPix[8-i] += 2; // if byte 2's bit is on
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", miniPix[i]);
    }
    return miniPix;
}
