//
//  cache.cpp
//  AssemblyProj2
//
//  Created by Mohamed El-Refai on 22/11/2024.
//

#include <vector>
#include <iostream>
#include "cache.h"
#include <iomanip>

using namespace std;

cache::cache(int s, int l, int a)
    : size(s), lineSize(l), accessTime(a), hits(0), misses(0), accesses(0) {
    initializeCache();
}

int cache::getSize() const { return size; }
int cache::getLineSize() const { return lineSize; }
int cache::getAccessTime() const { return accessTime; }
int cache::getHits() const { return hits; }
int cache::getMisses() const { return misses; }
int cache::getAccesses() const { return accesses; }

void cache::setSize(int s) { size = s; }
void cache::setLineSize(int l) { lineSize = l; }
void cache::setAccessTime(int a) { accessTime = a; };

void cache::initializeCache() {
    int numLines = size / lineSize;
    cacheLines.resize(numLines, {false, -1});
}

int cache::calculateIndex(int address) const {
    return (address / lineSize) % (size / lineSize);
}

int cache::calculateTag(int address) const {
    return address / size;
}

bool cache::accessMemory(int address, int &index, int &tag, bool &hit) {
    index = calculateIndex(address);
    tag = calculateTag(address);

    if (cacheLines[index].valid && cacheLines[index].tag == tag) {
        hit = true;
        hits++;
    } else {
        hit = false;
        misses++;
        cacheLines[index].valid = true;
        cacheLines[index].tag = tag;
    }
    accesses++;
    return hit;
}

void cache::displayCacheContents() const {
    cout << endl << "Cache contents: " << endl;
    cout << "Index" << setw(8) << "Valid" << setw(7) << "Tag" << endl;
    for (size_t i = 0; i < cacheLines.size(); ++i) {
        cout << setw(3) << i << setw(8) << cacheLines[i].valid << setw(8) << (cacheLines[i].valid ? to_string(cacheLines[i].tag) : "N/A") << endl;
    }
}
