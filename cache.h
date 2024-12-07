#include <vector>
#include "global.h"

using namespace std;



#ifndef CACHE_H
#define CACHE_H


class cache {
private:

vector<Byte> bytes;
vector<cacheLine> cacheLines;
    
int size;
int lineSize;
int accessTime;

int hits;
int misses;
int accesses;
    
public:

cache();
cache(int s, int l, int a);

//getters
int getSize() const;
int getLineSize() const;
int getAccessTime () const;

int getHits() const;
int getMisses() const;
int getAccesses() const;

//setters
void setSize(int s);
void setLineSize(int l);
void setAccessTime(int a);
//void setHits(int h);
//void setMisses(int m);

//cache operations
void initializeCache();
bool accessMemory(int address, int &index, int &tag, bool &hit);
void displayCacheContents() const;
    
//helper functions
int calculateIndex(int address) const;
int calculateTag(int address) const;
};

#endif //CACHE_H