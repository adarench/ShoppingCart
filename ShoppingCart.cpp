//
// Created by Adam Rencher on 4/1/22.
//

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(string aName, string aDate){
    customerName = aName;
    dateOfCreation = aDate;
}
ShoppingCart::ShoppingCart(){
    customerName = "None";
    dateOfCreation = "January 1, 1970";
}

void ShoppingCart::AddItem(ItemToPurchase item) {
    bool found = false;
    for(int i=0; i<Cart.size();i++){
        if(item.GetName() == Cart.at(i).GetName()){
            cout << "Item is already found in the cart. It will not be added." << endl;
            found = true;
        }
    }
    if(!found){
        Cart.push_back(item);
    }
}

void ShoppingCart::RemoveItem(string itemName) {
    bool found = false;
    for(int i=0; i<Cart.size();i++){
        if(itemName == Cart.at(i).GetName()){
            Cart.erase(Cart.begin()+i);
            found = true;
        }
    }
    if(!found){
        cout << "Item not found in cart. It will not be removed." << endl;
    }
}

void ShoppingCart::UpdateQuantity(int newQuantity, string itemName){
    for(int i=0; i<Cart.size();i++){
        if (itemName == Cart.at(i).GetName()){
            Cart.at(i).SetQuantity(newQuantity);
            return;
        }
    }
    cout << "Item not found in cart. It will not be modified." << endl;
}

void ShoppingCart::PrintDescription(){
    cout << customerName << "'s " << "Shopping cart - " << dateOfCreation << endl;

    if(Cart.size()==0){
        cout << "Shopping cart is empty." << endl;
    }
    else {
        cout << "Item Descriptions" << endl;
        for (int i = 0; i < Cart.size(); i++) {
            Cart.at(i).PrintDescription();
        }
    }

}

double ShoppingCart::CartCost() {
    double total = 0;
    for (int i = 0; i < Cart.size(); i++) {
        total += Cart.at(i).GetPrice() * Cart.at(i).GetQuantity();
    }
    return total;
}
void ShoppingCart::PrintCost() {
    cout << customerName << "'s " << "Shopping cart - " << dateOfCreation << endl;
    if(Cart.size()==0){
        cout << "Shopping cart is empty." << endl;
    }
    else {
        cout << "Number of Items: " << CartTotalQuantity();
        for (int i = 0; i < Cart.size(); i++) {
            Cart.at(i).PrintCostItem();
        }
        cout << endl << "Total: $" << CartCost();
        cout << endl;
    }
}

int ShoppingCart::CartTotalQuantity() {
    int total = 0;
    for(int i = 0; i < Cart.size(); i++){
        total += Cart.at(i).GetQuantity();
    }
    return total;
}
