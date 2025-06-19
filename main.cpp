#include <iostream>
#include "User/user.h"
#include "Menu/menu.h"
using namespace std;



    User user;
    Menu menu;

int main() 
{

    user.addUser("akbarzaqi", "123", "0895363163250");
    user.addUser("joko  ", "123", "0895363163250");
    user.addUser("budi", "123", "0895363163250");
    user.addUser("arvin", "123", "0895363163250");
    user.addUser("nagom", "123", "0895363163250");
    user.showUser();
    user.delUser(2);
    user.showUser();

    if(user.isLogin("akbarzaqi", "1223"))
    {
        cout << "login berhasil" << endl;
    }
    else
    {
        cout << "akun anda tidak terdaftar" << endl;
    }
    
    // menu.showMenu();
    // menu.delMenu(1);
    // menu.showMenu();
    menu.searchMenu("n");
   
}