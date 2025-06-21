#include <iostream>
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