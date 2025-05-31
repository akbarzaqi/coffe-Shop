#include <iostream>
#include <iomanip>
#include "user.h"

using namespace std;

bool User::isEmpty()
{
    if(top == 0)
        return true;
    else 
        return false;
}

bool User::isFull()
{
    if(top == MAX)
        return true;
    else 
        return false;
}

int User::countData()
{
    if(top == 0)
        return 0;
    else 
        return top;
}

void User::addUser(string username, string password, string no_telp)
{
    
    if(isFull())
    {
        cout << "data sudah penuh" << endl;
    }
    else 
    {
        user[top].id_user = top+1;
        user[top].username = username;
        user[top].password = password;
        user[top].no_telp = no_telp;

        top++;

        cout << "user berhasil ditambahkan!!" << endl;
    }

}

void User::delUser(int id)
{
    if(isEmpty())
    {
        cout << "maaf data anda kosong" << endl;
    }
    else 
    {
        int idx;

        for(int i = 0; i < countData(); i++)
        {
            if(user[i].id_user == id)
            {
                idx = i;
                break;
            }
        }

        user[idx].id_user = 0;
        user[idx].username = "";
        user[idx].password = "";
        user[idx].no_telp = "";

        for(int i = idx; i < countData(); i++)
        {
            user[i] = user[i+1];
        }

        top--;
        
        cout << "user berhasil dihapus" << endl;

    }
}

void User::showUser()
{
    if(isEmpty())
    {
        cout << "maaf data anda kosong" << endl;
    }
    else
    {
        cout << "=== DATA USER ===" << endl;

        cout << left
             << setw(10) << "ID User"
             << setw(20) << "Username"
             << setw(20) << "Password"
             << setw(15) << "No Telp"
             << endl;

        cout << string(70, '-') << endl;

        for (int i = 0; i < countData(); i++)
        {
            cout << left
                 << setw(10) << user[i].id_user
                 << setw(20) << user[i].username
                 << setw(20) << user[i].password
                 << setw(15) << user[i].no_telp
                 << endl;
        }
    }
}

bool User::isLogin(string uname, string pass)
{
    for(int i = 0; i < countData(); i++)
    {
        if(user[i].username == uname && user[i].password == pass)
        {
            return true;
            break;
        }

        
    }

    return false;
}
