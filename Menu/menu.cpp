#include <iostream>
#include <iomanip>
#include "menu.h"

using namespace std;

bool Menu::isEmpty()
{
    if(top == 0)
        return true;
    else 
        return false;
}

bool Menu::isFull()
{
    if(top == MAX)
        return true;
    else 
        return false;
}

int Menu::countData()
{
    if(top == 0)
        return 0;
    else 
        return top;
}

void Menu::addMenu(string menu_item, int price, int stock, string category)
{
    if(isFull())
    {
        cout << "data sudah penuh" << endl;
    }
    else 
    {
        menu[top].id_menu = top+1;
        menu[top].price = price;
        menu[top].stock = stock;
        menu[top].menu_item = menu_item;
        menu[top].category = category;

        top++;

        cout << "menu berhasil ditambahkan!!" << endl;
    }
}

void Menu::showMenu()
{
    if(isEmpty())
    {
        cout << "maaf data anda kosong" << endl;
    }
    else 
    {

    cout << "===== Menu Caffe =====" << endl;
    cout << left << setw(25) << "makanan" 
         << setw(10) << "harga" 
         << setw(25) << "minuman" 
         << "harga" << endl;

    int countFood = 0, countDrink = 0;
    for (int i = 0; i < countData(); i++) {
        string foodStr = "", drinkStr = "";
        int prcFood, prcDrink;

        while (countFood < countData()) {
            if (menu[countFood].category == "makanan") {
                foodStr = menu[countFood].menu_item;
                prcFood = menu[countFood].price;
                countFood++;
                break;
            }
            countFood++;
        }

        while (countDrink < countData()) {
            if (menu[countDrink].category == "minuman") {
                drinkStr = menu[countDrink].menu_item;
                prcDrink = menu[countDrink].price;
                countDrink++;
                break;
            }
            countDrink++;
        }

        if (foodStr == "" && drinkStr == "") break;

        cout << left << setw(25) << foodStr 
            << setw(10) << prcFood 
            << setw(25) << drinkStr
            << prcDrink << endl;
    }
    }
}

void Menu::init()
{
    addMenu("bakso", 10000, 2, "makanan");
    addMenu("fanta", 12000, 2, "minuman");

}

Menu::Menu()
{
    init();
}