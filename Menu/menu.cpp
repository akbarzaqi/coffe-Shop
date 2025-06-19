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
        int prcFood = 0, prcDrink = 0;

        while (countFood < countData()) {
            if (menu[countFood].category == "makanan") {
                foodStr = menu[countFood].menu_item;
                prcFood = menu[countFood].price;
                countFood++;
                break;
            }
            else 
            {

                countFood++;
            }
        }

        while (countDrink < countData()) {
            if (menu[countDrink].category == "minuman") {
                drinkStr = menu[countDrink].menu_item;
                prcDrink = menu[countDrink].price;
                countDrink++;
                break;
            }
            else 
            {

                countDrink++;
            }
        }
        if (foodStr == "" && drinkStr == "") break;  

         cout << left << setw(25) << foodStr 
                 << setw(10) << (prcFood != 0 ? to_string(prcFood) : "") 
                 << setw(25) << drinkStr
                 << (prcDrink != 0 ? to_string(prcDrink) : "") << endl;
    }
    }
}

bool Menu::checkString(string menu_item, string menu)
{
    for(int i = 0; i < countData(); i++)
    {
        for(int j = 0; i < countData(); j++)
        {
            cout << "menu item : " << menu_item[i] << endl;
            cout << "menu : " << menu[j] << endl;
            if(menu_item[i] == menu[j])
            {
                return true;
                break;
            }
        }
    }

    return false;

    
}

void Menu::searchMenu(string menu_item)
{
   
    if(isEmpty())
    {
        cout << "data kosong" << endl;
    }
    else 
    {
        int idx;
        for(int i = 0; i < countData(); i++)
        {
            cout << checkString(menu[i].menu_item, menu_item) << endl;
            if(checkString(menu[i].menu_item, menu_item))
            {
                cout << "id menu : " << menu[i].menu_item << endl;
            }   

        }
    }
}

void Menu::delMenu(int id)
{
    if(isEmpty())
    {
        cout << "Data kosong" << endl;
    }
    else 
    {
        int idx;
        bool found = false;
        for(int i = 0; i < countData(); i++)
        {
            if(menu[i].id_menu == id)
            {
                idx = i;
                found = true;
                break;
            }
        }
        if(found)
        {
            menu[idx].id_menu = 0;
            menu[idx].price = 0;
            menu[idx].stock = 0;
            menu[idx].menu_item = "";
            menu[idx].category = "";

            for(int i = idx; i < countData(); i++)
                menu[i] = menu[i+1];

            top--;
            cout << "data berhasil dihapus" << endl;
        }
        else 
        {
            cout << "data yang ingin anda hapus tidak tersedia!!" << endl;
        }
    }
}

void Menu::init()
{
    addMenu("bakso", 10000, 2, "makanan");
    addMenu("fanta", 12000, 2, "minuman");
    addMenu("bantal", 12000, 2, "minuman");

}

