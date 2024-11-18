#include "User.h"
#include <fstream>
#include <sstream>
#include <iostream>

UserManager::UserManager(const string& filename) {
    ifstream file(filename);
    string userid, hashedPassword;

    if (file.is_open()) {
        while (file >> userid >> hashedPassword) {
            users[userid] = hashedPassword;
        }
        file.close();
    }
}

string UserManager::hashPassword(const string& password) {
    unsigned long hash = 5381;
    for (char c : password) {
        hash = ((hash << 5) + hash) + c;
    }
    stringstream ss;
    ss << hex << hash;
    return ss.str();
}

bool UserManager::login(const string& userid, const string& password) {
    auto it = users.find(userid);
    if (it != users.end() && it->second == hashPassword(password)) {
        cout << "\033[32m\nLogin successful!\033[0m\n"; // Green text
        return true;
    }
    cout << "\033[31m\nInvalid username or password.\033[0m\n"; // Red text
    return false;
}

bool UserManager::signUp(const string& userid, const string& password) {
    if (users.find(userid) != users.end()) {
        cout << "\033[31m\nUser already exists. Try logging in.\033[0m\n"; // Red text
        return false;
    }
    users[userid] = hashPassword(password);
    cout << "\033[32m\nSign-up successful!\033[0m\n"; // Green text
    return true;
}

void UserManager::saveUsersToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& user : users) {
            file << user.first << " " << user.second << endl;
        }
        file.close();
    } else {
        cout << "\033[31m\nError saving user data.\033[0m\n"; // Red text
    }
}
