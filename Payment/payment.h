#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
using namespace std;

#define MAX 100

struct ItemList
{
    int idItem;
    string menuName;
    int qty;
    int subtotal;
};

struct DataPayment
{
    int idPayment;
    int idUser;
    string staffName;
    string customerName;
    string orderTime;
    string status;
    string paymentMethod;
    int totalPrice;
    int payback;

};

class Payment
{
    private:
        int countPayment = 0;
       
    
    public:
        int countItem = 0;
        int countItem2 = 0;
        DataPayment payment[MAX];
        ItemList item[MAX][MAX];
        
        void addPayment(int idUser, string staffName, string customerName, string orderTime, string status, string paymentMethod, int totalPrice, int payback);
        void addItemToPayment();
        void AddItem(int idItem, string menuName, int qty, int subtotal);
        void showPaymentList();
        void searchPayment();
        void delPayment();
        bool isPaymentEmpty();
        bool isItemEmpty();
        bool isPaymentFull();
        bool isItemFull();
        int countDataPayment();
        int countDataItem();


        
};




#endif