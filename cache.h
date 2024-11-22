#include <vector>

using namespace std;

const int BYTE_SIZE=8;



#ifndef CACHE_H
#define CACHE_H

struct Byte{
    vector<int> bits[BYTE_SIZE];

};

class cache {
private:

vector<Byte> bytes;
int size;
int lineSize;
int accessTime;

public:

cache();
cache(int s, int l, int a);

//getters
int getSize() const;
int getLineSize() const;
int getAccessTime () const;

//setters
void setSize(int s);
void setLineSize(int l);
void setAccessTime(int a);
};

#endif //CACHE_H