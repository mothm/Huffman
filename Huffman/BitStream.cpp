#include <iostream>
#include <fstream>

#include "BitStream.h"

void BitOutputStream::flush()
{
    out << buffer;
    buffer  = 0;
    bits    = 7;
}

void BitOutputStream::write(int num)
{
    int bit = num & 1;
    buffer |= bit << bits;
    bits--;
    if (bits < 0)
        flush();
}

void BitOutputStream::close()
{
    while (bits >= 0)
    {
        buffer |= 0 << bits;
        bits--;
    }
    flush();
    out.close();
    delete out;
}

int BitInputStream::readBit()
{
    if (bits < 0)
        byte = file.get();
    int val = 1;
    val <<= bits;
    int bitVal = val & byte;
    bitVal >>= bits;
    return bitVal;
}

void BitInputStream::close()
{
    file.close();
    out.close();
}
