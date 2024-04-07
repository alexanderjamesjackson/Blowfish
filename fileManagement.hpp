#include "blowfish.hpp"

vector<uint64_t> readFileAsBinary(const string & path);

void writeFileAsBinary(const string & path, const vector<uint64_t> & data);


class User{
    private:
        //Distinct user id per user generate when initialised 
        const uint64_t _userid;
        //Image of password from a hash function used for login 
        uint64_t _passwordHash;
        //Username for login
        string _username;
        //Function to hash a password 
        uint64_t hashPassword(const string & password);

    public:
        //Constuct a user with username and password sets the password hash and user id 
        User(const string & username,const string & password);

        void changePassword(const string & password);
        //return users encryption key
        vector<uint8_t> getKey() const;

};

