#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdio>
#include "User.h"
#include "ConsolMessage.h"

using namespace std;

class Users {
    vector<User> listOfUser;

    void addUser(User user);
    int idOfLastUser();
public:
    Users();
    void displayUsers();
    int numberOfRegisteredUsers();
    int logIn();
    void singUp();
    void changePassword(int idLoggedUser);
};
