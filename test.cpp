#include "fileManagement.hpp"

using namespace std;




int main(){
    vector<uint8_t> key = {0x00, 0x01, 0x10, 0x11,0xAB, 0xBC};

    Blowfish bc(key);


    // string command;
    // string currentState  = "<Encrypt String> <Decrypt String>";
    // string usrString;
    // vector<uint64_t> strData;

    

    // while (true) {
    //     cout << currentState << endl;
    //     cout<< ">>";
    //     getline(cin, command);

    //     if (command == "exit") {
    //         break;
    //     } 
        
    //     else if (command == "Encrypt String") {
    //         cout<< "Enter String: ";
    //         getline(cin,usrString);
    //         strData = encryptString(bc, usrString);
    //         cout << "Encrypted!" <<endl;
    //         cout << "Example Data: " << strData[0] << endl;
    //     } 

    //     else if (command == "Decrypt String") {
    //         // cout<< "Enter String: ";
    //         // getline(cin,usrString);
    //         string str = decryptData(bc, strData);
    //         cout << "Decrypted! : " << str << endl;
    //     } 

    //     else {
    //         cout << "Unknown command.\n";
    //     }
    // }

    // cout << "Goodbye!\n";

    string command;
    string currentState  = "<Encrypt File> <Decrypt File>";
    string path;
    vector<uint64_t> strData;
    string str;

    while (true) {
        cout << currentState << endl;
        cout<< ">>";
        getline(cin, command);

        if (command == "exit") {
            break;
        } 
        
        else if (command == "Encrypt File") {
            cout<< "Enter Path To Input: ";
            getline(cin,path);

            str = readFileToString(path);
            
            
            strData = encryptString(bc, str);

            cout << "Enter Path To Output: ";
            getline(cin,path);

            saveEncryptedToFile(strData, path);

            cout << "Encrypted!" <<endl;
            
        } 

        else if (command == "Decrypt File") {
            cout<< "Enter Path To Input: ";
            getline(cin,path);

            strData = readEncryptedFromFile(path);

            str = decryptData(bc, strData);

            cout << "Enter Path To Output: ";

            getline(cin,path);

            saveStringToFile(str, path);

            cout << "Decrypted!" <<endl;
        } 

        else {
            cout << "Unknown command.\n";
        }
    }

    cout << "Goodbye!\n";
}