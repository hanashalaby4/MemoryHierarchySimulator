#include <iostream>
#include "cache.h"
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int memoryBits, memoryAccessTime, cacheSize, lineSize, accessTime, cacheLevels;
    int totalAccesses = 0, totalHits = 0, totalMisses = 0;

    // Prompt user for memory details
    cout << "Enter the number of bits needed to address the memory (16-40): ";
    cin >> memoryBits;
    while (memoryBits < 16 || memoryBits > 40) {
        cout << "Invalid input! Please enter a value between 16 and 40: ";
        cin >> memoryBits;
    }

    cout << "Enter the memory access time (in cycles, 50-200): ";
    cin >> memoryAccessTime;
    while (memoryAccessTime < 50 || memoryAccessTime > 200) {
        cout << "Invalid input! Please enter a value between 50 and 200: ";
        cin >> memoryAccessTime;
    }

    // Calculate memory size based on bits
    long long memorySize = pow(2, memoryBits);

    // Prompt user for cache hierarchy details
    cout << "Enter number of cache levels: ";
    cin >> cacheLevels;

    vector<cache> hierarchy;

    for (int i = 0; i < cacheLevels; i++) {
        cout << "Enter cache " << i + 1 << " size (in bytes): ";
        cin >> cacheSize;

        cout << "Enter cache " << i + 1 << " line size (in bytes): ";
        cin >> lineSize;

        cout << "Enter cache " << i + 1 << " access time (in cycles): ";
        cin >> accessTime;

        cache newCache(cacheSize, lineSize, accessTime);
        hierarchy.push_back(newCache);
    }

    // Read access sequence file
    string filename = "/Users/refobic/Documents/Assembly/AssemblyProj2/AssemblyProj2/AssemblyProj2/access_sequence.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    vector<int> accessSequence;
    string address;
    while (getline(file, address, ',')) {
        accessSequence.push_back(stoi(address));
    }
    file.close();

    // Simulate cache hierarchy
    for (int address : accessSequence) {
        int level = 0;
        int index, tag;
        bool hit;

        do {
            hit = hierarchy[level].accessMemory(address, index, tag, hit);
            cout << "Cache level: " << level + 1
                 << ", Accessing address: " << address
                 << " -> Index: " << index
                 << ", Tag: " << tag
                 << " -> Result: " << (hit ? "Hit" : "Miss") << endl;

            level++;
        } while (!hit && level < cacheLevels);

        totalHits = 0;
        totalMisses = 0;
        totalAccesses = 0;
        for (const auto &cacheLevel : hierarchy) {
            totalHits += cacheLevel.getHits();
            totalMisses += cacheLevel.getMisses();
            totalAccesses += cacheLevel.getAccesses();
        }

        cout << "Accessing address: " << address
             << " -> Result: " << (hit ? "Hit" : "Miss") << endl;
        cout << "Total hits so far: " << totalHits
             << " Total misses so far: " << totalMisses
             << " Total accesses so far: " << totalAccesses << endl
             << endl;
    }

    // Display final results
    for (int i = 0; i < cacheLevels; i++) {
        hierarchy[i].displayCacheContents();

        double hitRatio = static_cast<double>(hierarchy[i].getHits()) / hierarchy[i].getAccesses();
        double missRatio = static_cast<double>(hierarchy[i].getMisses()) / hierarchy[i].getAccesses();
        double nextLevelPenalty = (i + 1 < cacheLevels) ? hierarchy[i + 1].getAccessTime() : memoryAccessTime;
        double AMAT = hierarchy[i].getAccessTime() + missRatio * nextLevelPenalty;

        cout << fixed << setprecision(2);
        cout << "Cache Level " << i + 1 << ":\n";
        cout << "Hit Ratio: " << hitRatio << endl;
        cout << "Miss Ratio: " << missRatio << endl;
        cout << "Average Memory Access Time: " << AMAT << " cycles\n\n";
    }

    return 0;
}
