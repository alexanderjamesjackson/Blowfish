#include "blowfish.hpp"


using namespace std;

int main(){
    vector<uint8_t> keyCorrect = {0x00, 0x01, 0x10, 0x11};
    vector<uint8_t> keyWrong = {0x00, 0x10, 0x01, 0x11};

    Blowfish bc(keyCorrect);

    uint64_t data = 0x0123456789ABCDEF; 
    cout << "Data before Encryption: "<< data << endl;

    bc.encrypt(data);
    cout<< "Data after Encryption: " << data << endl; 
    uint64_t encryptedData = data;

    bc.decrypt(data);
    cout<<"Data after Decryption using correct key: " << data << endl;

    Blowfish bw(keyWrong);

    bw.decrypt(encryptedData);

    cout<<"Data after Decryption using wrong key: " << encryptedData << endl;
}