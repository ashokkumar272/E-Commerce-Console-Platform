#ifndef USER_H
#define USER_H

#include <string>
#include <unordered_map>
using namespace std;

class UserManager {
    unordered_map<string, string> users;

public:
    UserManager(const string& filename);
    bool login(const string& userid, const string& password);
    bool signUp(const string& userid, const string& password);
    void saveUsersToFile(const string& filename);
    string hashPassword(const string& password);
};

#endif
