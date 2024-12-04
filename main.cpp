//
//  main.cpp
//  AssemblyProj2
//
//  Created by Mohamed El-Refai on 22/11/2024.
//

#include <iostream>
#include "cache.h"
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int memorySize, cacheSize, lineSize, accessTime;
    string filename = "/Users/refobic/Documents/Assembly/AssemblyProj2/AssemblyProj2/AssemblyProj2/access_sequence.txt";

    cout << "Enter cache size (in bytes): ";
    cin >> cacheSize;

    cout << "Enter cache line size (in bytes): ";
    cin >> lineSize;

    cout << "Enter cache access time (in cycles): ";
    cin >> accessTime;

    cache cache(cacheSize, lineSize, accessTime);

    //read file
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

    for (int address : accessSequence) {
        int index, tag;
        bool hit;

        cache.accessMemory(address, index, tag, hit);

        cout << "Accessing address: " << address << " -> Index: " << index << ", Tag: " << tag << endl << "Result: " << (hit ? "Hit" : "Miss") << endl;
    }

    //display results
    cache.displayCacheContents();

    double hitRatio = static_cast<double>(cache.getHits()) / cache.getAccesses();
    double missRatio = static_cast<double>(cache.getMisses()) / cache.getAccesses();
    cout << fixed << setprecision(2);
    cout << endl << "Hit ratio: " << hitRatio << endl;
    cout << "Miss ratio: " << missRatio << endl;

    return 0;
}

