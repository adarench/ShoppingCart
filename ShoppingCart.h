#ifndef SHOPPINGCART_H_
#define SHOPPINGCART_H_

#include "ItemToPurchase.h"
#include <iostream>
#include <vector>

using namespace std;

class ShoppingCart{
private:
    string customerName;
    string dateOfCreation;
    vector<ItemToPurchase> Cart;
public:

    ShoppingCart(string aName, string aDate);
    ShoppingCart();
    void AddItem(ItemToPurchase item);
    void RemoveItem(string itemName);
    void UpdateQuantity(int newQuantity, string itemName);
    double CartCost();
    void PrintDescription();
    void PrintCost();
    int CartTotalQuantity();

    //getter for the name and the date
};

#endif
