#include "fileManagement.hpp"

using namespace std;




int main(){

    string command;
    string menu  = "<Encrypt File> <Decrypt File>";
    string path;
    vector<uint64_t> strData;
    string str;
    string password;


    while (true) {
        cout << menu << endl;
        cout<< ">>";
        getline(cin, command);

        if (command == "exit") {
            break;
        } 
        
        else if (command == "Encrypt File") {
            cout<< "Enter Path To Input: ";
            getline(cin,path);

            str = readFileToString(path);

            cout<< "Enter Encryption Password: ";
            getline(cin,password);
            vector<uint8_t> key = stringToKey(password);
            
    
            Blowfish b(key);

            strData = encryptString(b, str);

            cout << "Enter Path To Output: ";
            getline(cin,path);

            saveEncryptedToFile(strData, path);

            cout << "Encrypted!" <<endl;
            
        } 

        else if (command == "Decrypt File") {
            cout<< "Enter Path To Input: ";
            getline(cin,path);

            strData = readEncryptedFromFile(path);

            cout<< "Enter Encryption Password: ";
            getline(cin,password);

            vector<uint8_t> key = stringToKey(password);

            Blowfish b(key);

            str = decryptData(b, strData);

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