#include <iostream>
#include <iomanip>
#include "orderitem.h"

using namespace std;

bool OrderItem::isFull()
{
    if(top == MAX)
        return true;
    else 
        return false;
}

bool OrderItem::isEmpty()
{
    if(top == 0)
        return true;
    else 
        return false;
}

int OrderItem::countData()
{
    if(top == 0)
        return 0;
    else 
        return top;
}

void OrderItem::addItem(int IdItem, string menuName, int qty, int subtotal)
{
    if(isFull())
    {
        cout << "data sudah penuh" << endl;
    }
    else 
    {
        order[top].idItem = IdItem;
        order[top].menuName = menuName;
        order[top].qty = qty;
        order[top].subtotal = subtotal;

        top++;
    }
}

void OrderItem::showOrderItem()
{
    if(isEmpty())
    {
        cout << "data kosong" << endl;
    }
    else 
    {
        cout << "\t\t\t\t=== Daftar Pesanan ===" << endl;
        
        cout << left
             << setw(10) << "ID Item"
             << setw(20) << "Nama Menu"
             << setw(20) << "Qty"
             << setw(15) << "Subtotal"
             << endl;

        cout << string(70, '-') << endl;

        for (int i = 0; i < countData(); i++)
        {
            cout << left
                 << setw(10) << order[i].idItem
                 << setw(20) << order[i].menuName
                 << setw(20) << order[i].qty
                 << setw(15) << order[i].subtotal
                 << endl;
        }
    }
    cout << endl;
}

void OrderItem::delOrderItem(int id)
{
    if(isEmpty())
    {
        cout << "data kosong" << endl;
    }
    else 
    {
        int idx;
        bool found = false;
        for(int i = 0; i < countData(); i++)
        {
            if(order[i].idItem == id)
            {
                idx = i;
                found = true;
                break;
            }
        }

        if(found)
        {
            order[idx].idItem = 0;
            order[idx].menuName = "";
            order[idx].qty = 0;
            order[idx].subtotal = 0;

            for(int i = idx; i < countData(); i++)
            {
                order[i] = order[i+1];
            }

            top--;
            cout << "data berhasil dihapus" << endl;

        }
        else
        {
            cout << "id yang anda masukan tidak tersedia" << endl;
        }


    }
}

int OrderItem::countString(string text)
{
    int i = 0;
    while(text[i] != '\0')
    {
        // cout << text[i] << " ";
        i++;
    }

    return i;
}

bool OrderItem::checkString(string OrderItem, string pattern)
{
    int n = countString(OrderItem);
    int m = countString(pattern);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (OrderItem[i + j] != pattern[j])
                break;
        }
    
        if (j == m  )
            return true;
    }
    return false;
}

void OrderItem::searchOrderItem(string pattern)
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
            if(checkString(order[i].menuName, pattern))
            {
                cout << "id order : " << order[i].menuName << endl;
            }   

        }
    }
}
void OrderItem::updateOrderItem(int id, int newQty, int price)
{
    if(isEmpty())
    {
        cout << "data anda kosong" << endl;
    }
    else 
    {
        int idx;
        for(int i = 0; i < countData(); i++)
        {
            if(id == order[i].idItem)
                idx = i;
        }

        order[idx].qty = newQty;

    }
}
