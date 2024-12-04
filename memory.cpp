#include <vector>
#include "memory.h"

    memory::memory() {}
    memory:: memory(int a, int m) : addressBitNo(a), memAccessTime(m) {
        long memorySize = pow(2, addressBitNo); //2^a bytes
        vector<Byte> mem(memorySize); }

    //getters
    int memory::getAddressBitNo() const { return addressBitNo; };
    int memory::getMemAccessTime() const { return memAccessTime; };

    //setters
    void memory::setAddressBitNo(int a) { addressBitNo = a; };
    void memory::setMemAccessTime(int m) { memAccessTime = m; };