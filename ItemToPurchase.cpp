//
// Created by Adam Rencher on 4/1/22.
//

#include "ItemToPurchase.h"
#include <iostream>
#include <iomanip>

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}

void ItemToPurchase::SetName(string name) {
    itemName = name;
}

void ItemToPurchase::SetPrice(double price) {
    itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

string ItemToPurchase::GetName() {
    return itemName;
}

double ItemToPurchase::GetPrice() {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}

ItemToPurchase::ItemToPurchase(string name, string description, double price, int quantity){
    itemName = name;
    itemDescription = description;
    itemQuantity = quantity;
    itemPrice = price;
}

void ItemToPurchase::PrintCostItem() {
    cout << fixed << setprecision(2);
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;

}

void ItemToPurchase::PrintDescription() {
    cout << itemName << ": " << itemDescription << endl;
}

void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;
}

string ItemToPurchase::GetDescription() {
    return itemDescription;
}

