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
        void addItem();
        void showOrderItem();
        void delOrderItem();
        void searchOrderItem();
        void updateOrderItem();
        bool isEmpty();
        bool isFull();
        int countData();

};






#endif 
