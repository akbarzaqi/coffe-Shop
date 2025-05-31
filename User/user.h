#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

#define MAX 100

struct Data
{
    int id_user;
    string no_telp;
    string username;
    string password;
};

class User
{
    private:
        int top = 0;

    public:
        Data user[MAX];
        void addUser(string username, string password, string no_telp);
        void delUser(int id);
        void showUser();
        bool isEmpty();
        bool isFull();
        bool isLogin(string uname, string pass);
        int countData();


};

#endif