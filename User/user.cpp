#include <iostream>
#include <iomanip>
#include <string>
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

void User::updateData(int id)
{
    if(isEmpty())
    {
        cout << "data kosong" << endl;
    }
    else 
    {
        int choose;
        int idx;
        string uname, pass, no_telp;
        bool found = false;

        for(int i = 0; i < countData(); i++)
        {
            if(id == user[i].id_user)
            {
                idx = i;
                found = true;
                break;
            }
          
        }

        if(found)
        {
            cout << "1. Edit username" << endl;
            cout << "2. Edit password" << endl;
            cout << "3. Edit no telp" << endl;
            cout << "masukan pilihan : ";
            cin >> choose;
            cout << endl;
            
            switch (choose)
            {
            case 1:
                cin.ignore();
                cout << "masukan username baru : ";
                getline(cin, uname);
                user[idx].username = uname;
                break;
            
            case 2:
                cin.ignore();
                cout << "masukan password baru : ";
                getline(cin, pass);
                user[idx].password = pass;
                break;
            case 3:
                cin.ignore();
                cout << "masukan no telp baru : ";
                getline(cin, no_telp);
                user[idx].no_telp = no_telp;
                break;
            default:
                cout << "inputan yang anda masukan tidak sesuai" << endl;
                break;
            }
        }
        else 
        {
            cout << "data tidak ada" << endl;
        }

        

    }
}
