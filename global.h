#ifndef GLOBAL_H
#define GLOBAL_H
 #include <vector>
 using namespace std;
 
 const int BYTE_SIZE=8;

 struct cacheLine{
    int tag;
    bool valid;
};


struct Byte{
    vector<int> bits[BYTE_SIZE];
};
#endif //GLOBAL_H