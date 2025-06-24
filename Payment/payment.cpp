#include <iostream>
#include <iomanip>
#include <string>
#include "payment.h"

using namespace std;

bool Payment::isItemEmpty()
{
    if(countItem2 == 0)
        return true;
    else 
        return false;
}

bool Payment::isItemFull()
{
    if(countItem2 == MAX)
        return true;
    else    
        return false;
}

bool Payment::isPaymentEmpty()
{
    if(countPayment == 0)
        return true;
    else
        return false;
}

bool Payment::isPaymentFull()
{
    if(countPayment == MAX)     
        return true;
    else    
        return false;
}

int Payment::countDataItem()
{
    if(countItem2 == 0)
        return 0;
    else    
        return countItem2;
}

int Payment::countDataPayment()
{
    if(countPayment == 0)
        return 0;
    else 
        return countPayment;
}



void Payment::addPayment( int idUser, string staffName, string customerName, string orderTime, string status, string paymentMethod, int totalPrice, int payback)
{
    if(isPaymentFull())
    {
        cout << "data sudah penuh" << endl;
    }
    else 
    {
        payment[countPayment].idPayment = countPayment+1;
        payment[countPayment].idUser = idUser;
        payment[countPayment].staffName = staffName;
        payment[countPayment].customerName = customerName;
        payment[countPayment].orderTime = orderTime;
        payment[countPayment].status = status;
        payment[countPayment].paymentMethod = paymentMethod;
        payment[countPayment].totalPrice = totalPrice;
        payment[countPayment].payback = payback;
    
        countPayment++;

        cout << "pembayaran berhasil" << endl;

    }
}

void Payment::AddItem(int idItem, string menuName, int qty, int subtotal)
{
    
    if(isItemFull())
    {
        cout << "data sudah penuh" << endl;
    }
    else 
    {
        item[countItem][countItem2].idItem = idItem;
        item[countItem][countItem2].menuName = menuName;
        item[countItem][countItem2].qty = qty;
        item[countItem][countItem2].subtotal = subtotal;
    
        countItem2++;
    }

   
}

void Payment::addItemToPayment()
{
    countItem++;
}

void Payment::showPaymentList()
{
     cout << "=== Data Payment ===" << endl << endl;

    for (int i = 0; i < countDataPayment(); i++) {
        
        cout << left << setw(18) << "ID Payment:" << payment[i].idPayment << endl;
        cout << left << setw(18) << "ID User:" << payment[i].idUser << endl;
        cout << left << setw(18) << "Staff Name:" << payment[i].staffName << endl;
        cout << left << setw(18) << "Customer Name:" << payment[i].customerName << endl;
        cout << left << setw(18) << "Order Time:" << payment[i].orderTime << endl;
        cout << left << setw(18) << "Status:" << payment[i].status << endl;
        cout << left << setw(18) << "Payment Method:" << payment[i].paymentMethod << endl;
        cout << left << setw(18) << "Total Price:" << payment[i].totalPrice << endl;
        cout << left << setw(18) << "Payback:" << payment[i].payback << endl;

        cout << "=== Item List ===" << endl;
        cout << left
             << setw(10) << "ID"
             << setw(25) << "Menu Name"
             << setw(10) << "Qty"
             << setw(12) << "Subtotal" << endl;

        for (int k = 0; k < countDataItem(); k++) {
            cout << left
                 << setw(10) << item[i][k].idItem
                 << setw(25) << item[i][k].menuName
                 << setw(10) << item[i][k].qty
                 << setw(12) << item[i][k].subtotal << endl;
        }

        cout << "----------------------------------------" << endl;
    }
}