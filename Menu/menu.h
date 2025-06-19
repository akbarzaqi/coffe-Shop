#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

#define MAX 100

struct DataMenu
{
    int id_menu;
    int price;
    int stock;
    string menu_item;
    string category;

};

class Menu
{
private:
   int top = 0;
public:
    DataMenu menu[MAX];

    Menu()
    {
       init();
    }
    void init();
    void addMenu(string menu_item, int price, int stock, string category);
    void showMenu();
    void delMenu(int id);
    void searchMenu(string menu_item);
    void updateMenu();
    bool isEmpty();
    bool isFull();
    bool checkString(string menu_item, string menu);
    int countData();

   
};
#endif