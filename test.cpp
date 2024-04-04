#include "blowfish.hpp"

using namespace std;




int main(){
    vector<uint8_t> key = {0x00, 0x01, 0x10, 0x11,0xAB, 0xBC};

    Blowfish bc(key);


    string command;
    string currentState  = "<Encrypt String> <Decrypt String>";
    string usrString;
    vector<uint64_t> strData;

    

    while (true) {
        cout << currentState << endl;
        cout<< ">>";
        getline(cin, command);

        if (command == "exit") {
            break;
        } 
        
        else if (command == "Encrypt String") {
            cout<< "Enter String: ";
            getline(cin,usrString);
            strData = encryptString(bc, usrString);
            cout << "Encrypted!" <<endl;
            cout << "Example Data: " << strData[0] << endl;
        } 

        else if (command == "Decrypt String") {
            // cout<< "Enter String: ";
            // getline(cin,usrString);
            string str = decryptData(bc, strData);
            cout << "Decrypted! : " << str << endl;
        } 

        else {
            cout << "Unknown command.\n";
        }
    }

    cout << "Goodbye!\n";
}