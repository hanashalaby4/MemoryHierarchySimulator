 #include <vector>
 using namespace std;
 
 const int BYTE_SIZE=8;
 
 struct CacheLine{
    int tag;
    bool valid;
};


struct Byte{
    vector<int> bits[BYTE_SIZE];
};