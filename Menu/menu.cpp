#include <iostream>
#include <string>
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
    cout << "\t\t\t\t===== Menu Caffe =====" << endl << endl;
    cout << left 
         << setw(5) << "ID" 
         << setw(25) << "Makanan" 
         << setw(10) << "Harga" 
         << setw(5) << "ID" 
         << setw(25) << "Minuman" 
         << "Harga" << endl;

    int countFood = 0, countDrink = 0;
    for (int i = 0; i < countData(); i++) {
        string foodStr = "", drinkStr = "";
        int prcFood = 0, prcDrink = 0, idFood = 0, idDrink = 0;

        while (countFood < countData()) {
            if (menu[countFood].category == "makanan") {
                foodStr = menu[countFood].menu_item;
                prcFood = menu[countFood].price;
                idFood = menu[countFood].id_menu;
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
                idDrink = menu[countDrink].id_menu;
                countDrink++;
                break;
            }
            else 
            {

                countDrink++;
            }
        }
        if (foodStr == "" && drinkStr == "") break;  

        cout << left 
        << setw(5)  << (idFood != 0 ? to_string(idFood) : "")
        << setw(25) << foodStr 
        << setw(10) << (prcFood != 0 ? to_string(prcFood) : "") 
        << setw(5)  << (idDrink != 0 ? to_string(idDrink) : "") 
        << setw(25) << drinkStr 
        << (prcDrink != 0 ? to_string(prcDrink) : "") 
        << endl;
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

void Menu::updateMenu(int id)
{
    int choose, newPrice, newStock, choise;
    string newName, newCategory;
    bool success = false;

    if(isEmpty())
    {
        cout << "data anda kosong" << endl;
    }
    else 
    {
        int idx;
        for(int i = 0; i < countData(); i++)
        {
            if(id == menu[i].id_menu)
            {
                idx = i;
                break;
            }
        }

        cout << "1. Edit nama menu" << endl;
        cout << "2. Edit harga " << endl;
        cout << "3. Edit stok" << endl;
        cout << "4. Edit kategori" << endl;
        cout << "masukan pilihan : " << endl;
        cin >> choose;
        cout << endl;

        switch (choose)
        {
        case 1:
            cin.ignore();
            cout << "Masukan nama menu baru : ";
            getline(cin, newName);
            menu[idx].menu_item = newName;
            success = true;
            break;

        case 2:
            cout << "Masukan harga baru : ";
            cin >> newPrice;
            menu[idx].price = newPrice;
            success = true;
            break;

        case 3:
            cout << "Masukan stok baru : ";
            cin >> newStock;
            menu[idx].stock = newStock;
            success = true;
            break;
        
        case 4:
            cout << "1. makanan" << endl;
            cout << "2. minuman" << endl;
            cout << "masukan pilihan : ";
            cin >> choise;

            if(choise == 1)
                newCategory = "makanan";
            else if (choise == 2)
                newCategory = "minuman";
            
            menu[idx].category = newCategory;
            success = true;
            break;

        default:
            cout << "inputan tidak sesuai" << endl;
            break;
        }

        if(success)
            cout << "data berhasil diupdate!!" << endl;
    }
}

void Menu::init()
{
    addMenu("bakso", 10000, 2, "makanan");
    addMenu("fanta", 12000, 2, "minuman");
    addMenu("bantal", 12000, 2, "minuman");

}

