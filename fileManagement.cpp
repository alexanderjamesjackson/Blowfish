#include "fileManagement.hpp"


string readFileToString(const string & path){
    //read file specified by path in binary mode
    ifstream file(path, ios::binary);

    //Create string from start of file to end of file
    string content( (istreambuf_iterator<char>(file)) , istreambuf_iterator<char>() );

    return content;
};

void saveEncryptedToFile(const vector<uint64_t> & data , const string & outputPath){
    //Creates object to write to the output path in binary mode
    ofstream outFile(outputPath, ios::binary);
    for(int i = 0 ; i < data.size() ; i ++){

        //Write data, interpret the 64 bit data as a series of bytes to write
        outFile.write(reinterpret_cast<const char*>(&data[i]), sizeof(data[i]));

    }
};

vector<uint64_t> readEncryptedFromFile(const string & path){
    vector<uint64_t> data;
    ifstream file(path, ios::binary);
    uint64_t block;

    //While there is data to be read from the file add it to data
    while(file.read(reinterpret_cast<char*>(&block), sizeof(block))){
        data.push_back(block);
    }

    return data;
};

void saveStringToFile(const string& str, const string& outputPath){
    ofstream file(outputPath);
    file << str;
};