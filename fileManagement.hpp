#include "blowfish.hpp"


string readFileToString(const string & path);

void saveEncryptedToFile(const vector<uint64_t> & data, const string & outputPath);

vector<uint64_t> readEncryptedFromFile(const string & path);

void saveStringToFile(const string & str, const string & outputPath);





