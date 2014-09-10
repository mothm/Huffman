#ifndef BITSTREAM_H
#define BITSTREAM_H

#include <iostream>
#include <fstream>

class BitOutputStream
{
private:
    char buffer;
    int bits;
    std::ostream& out;

public:
    BitOutputStream(std::ofstream& os) : out(os, ios::binary)
    {
        buffer  = 0;
        bits    = 7;
    }

    void flush();
    void write(int num);
    void close();
};

class BitInputStream
{
private:
    char buffer;
    int bits;
    char byte;
    std::ostream& out;
    std::ifstream& file;

public:
    BitInputStream(std::ofstream& os, std::ifstream& ins) : out(os),
                                                           file(ins,
                                                                ios::binary)
    {
        buffer = 0;
        bits   = 7;
        byte   = file.get();
    }

    int readBit();
    void close();
}

#endif
