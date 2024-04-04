#include <stdint.h>
#include <vector>
#include <iostream>
using namespace std;

class Blowfish{
    private:
        //Define p array and sBox for encryption 
        vector<uint32_t> _pArray;
        vector<vector<uint32_t> > _sBox;
        uint32_t Ffunction(uint32_t data);
    public:
        Blowfish(vector<uint8_t> key);
        void setKey(vector<uint8_t> key);
        void encrypt(uint64_t & data);
        void decrypt(uint64_t & data);
};