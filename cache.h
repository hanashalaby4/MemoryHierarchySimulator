
//
//  cache.h
//  AssemblyProj2
//
//  Created by Mohamed El-Refai on 22/11/2024.
//

#include <vector>

using namespace std;

const int BYTE_SIZE=8;

#ifndef CACHE_H
#define CACHE_H

struct Byte{
    vector<int> bits[BYTE_SIZE];

};

struct cacheLine {
    bool valid;
    int tag;
};

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

//cache operations
void initializeCache();
bool accessMemory(int address, int &index, int &tag, bool &hit);
void displayCacheContents() const;
    
//helper functions
int calculateIndex(int address) const;
int calculateTag(int address) const;
};

#endif //CACHE_H
