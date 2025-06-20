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

int Menu::countText(string text)
{
    int i = 0;
    while(text[i] != '\0')
    {
        // cout << text[i] << " ";
        i++;
    }

    return i;
}

bool Menu::checkString(string menu_item, string textMenu)
{
    int n = countText(menu_item);
    int m = countText(textMenu);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (menu_item[i + j] != textMenu[j])
                break;
        }
    
        if (j == m  )
            return true;
    }
    return false;

    
}

void Menu::searchMenu(string textMenu)
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
            // cout << checkString(menu[i].menu_item, textMenu) << endl;
            if(checkString(menu[i].menu_item, textMenu))
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

