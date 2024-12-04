#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <cmath>
using namespace std;

const int BYTE_SIZE=8;
struct Byte{
    vector<int> bits[BYTE_SIZE];
};

class memory {

private:

    
    int addressBitNo;
    int memAccessTime;
    //num of blocks var?
    vector<Byte> mem; //contains actual contents

public:

    memory();
    memory(int a, int m);

    //getters
    int getAddressBitNo() const;
    int getMemAccessTime() const;

    //setters
    void setAddressBitNo(int a);
    void setMemAccessTime(int m);
  

};
#endif //MEMORY_H