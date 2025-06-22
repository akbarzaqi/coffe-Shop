#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <iostream>
using namespace std;

#define MAX 100

struct DataOrder
{
    int idItem;
    string menuName;
    int qty;
    int subtotal;
};

class OrderItem
{
    private:
        int top = 0;
    
    public:
        DataOrder order[MAX];
        void addItem(int idItem, string menuName, int qty, int subtotal);
        void showOrderItem();
        void delOrderItem(int id);
        void searchOrderItem(string pattern);
        void updateOrderItem(int id, int newQty, int price);
        bool isEmpty();
        bool isFull();
        bool checkString(string orderItem, string pattern);
        int countString(string text);
        int countData();

};






#endif 
