#include <iostream>
#include "cache.h"
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int memorySize, cacheSize, lineSize, accessTime, cacheLevels; 
    int totalAccesses, totalHits, totalMisses;
    totalHits = 0;
    totalMisses = 0;
    totalAccesses = 0;
    string filename = "/Users/hanashalaby/Desktop/AUC/Assembly/MemoryHierarchySimulator/access_sequence.txt";


    cout << "Enter number of cache levels: ";
    cin >> cacheLevels; 

    vector<cache> hierarchy;
 
    for (int i = 0; i < cacheLevels; i++) {
      
    cout << "Enter cache "<< i + 1 << " size (in bytes): ";
    cin >> cacheSize;

    cout << "Enter cache "<< i + 1<< " line size (in bytes): ";
    cin >> lineSize;

    cout << "Enter cache "<< i + 1 << " access time (in cycles): ";
    cin >> accessTime;

    cache newCache(cacheSize, lineSize, accessTime);
    hierarchy.push_back(newCache);

    }
   

    //read file
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    //read sequence
    vector<int> accessSequence;
    string address;
    while (getline(file, address, ',')) {
        accessSequence.push_back(stoi(address));
    }
    file.close();

    //access cache
    int level = 0;
    for (int address : accessSequence) {
        level = 0;
        int index, tag;
        bool hit;
        
       do {
            hit = hierarchy[level].accessMemory(address, index, tag, hit);
            cout <<"Cache level: "<< level + 1
                 << ", Accessing address: " << address
                 << " -> Index: " << index
                 << ", Tag: " << tag
                 << " -> Result: " << (hit ? "Hit" : "Miss") << endl;
            

            level++;
        } while (!hit && level < cacheLevels);

    int totalHits = 0, totalMisses = 0, totalAccesses = 0;
    for (const auto& cacheLevel : hierarchy) {
        totalHits += cacheLevel.getHits();
        totalMisses += cacheLevel.getMisses();
        totalAccesses += cacheLevel.getAccesses();
    }

    // Output details of the current memory access
    cout << "Accessing address: " << address
         << " -> Result: " << (hit ? "Hit" : "Miss") << endl;
    cout << "Total hits so far: " << totalHits
         << " Total misses so far: " << totalMisses
         << " Total accesses so far: " << totalAccesses << endl << endl;

        //cout << "Accessing address: " << address << " -> Index: " << index << ", Tag: " << tag << endl << "Result: " << (hit ? "Hit" : "Miss") << endl;
        //cout << "Total hits so far: " << hierarchy[level].getHits() << " Total misses so far: " << hierarchy[level].getMisses() <<  " Total accesses so far: " << hierarchy[level].getAccesses() << endl;
    }

    //display results
    for(int i = 0; i < cacheLevels; i++) {
        hierarchy[i].displayCacheContents();

        double hitRatio = static_cast<double>(hierarchy[i].getHits()) / hierarchy[i].getAccesses();
        double missRatio = static_cast<double>(hierarchy[i].getMisses()) / hierarchy[i].getAccesses();
        double nextLevelPenalty = (i + 1 < cacheLevels) ? hierarchy[i + 1].getAccessTime() : memorySize;
        double AMAT = hierarchy[i].getAccessTime() + missRatio * nextLevelPenalty;

        cout << fixed << setprecision(2);
        cout << endl << "Hit ratio: " << hitRatio << endl;
        cout << "Miss ratio: " << missRatio << endl;
        cout << "Average Memory Access Time: " << AMAT << endl;
        }
   

    

    return 0;
}

