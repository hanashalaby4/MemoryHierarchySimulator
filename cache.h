#include <vector>

using namespace std;





#ifndef CACHE_H
#define CACHE_H

const int BYTE_SIZE=8;

struct CacheLine{
    int tag;
    bool valid;
};

class cache {
private:

vector<CacheLine> cacheLines;
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