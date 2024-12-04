#include <vector>
#include "cache.h"

cache::cache(int s, int l, int a) : size(s), lineSize(l), accessTime(a) {

int numOfLines = size/lineSize;
cacheLines.resize(numOfLines, {false, -1});

}

int cache::getSize() const { return size; }
int cache::getLineSize() const { return lineSize; }
int cache::getAccessTime () const { return accessTime; }

void cache::setSize(int s) { size = s; }
void cache::setLineSize(int l) { lineSize = l; }
void cache::setAccessTime(int a) { if(a>=1 && a<=10) accessTime = a; else accessTime = -1; };


