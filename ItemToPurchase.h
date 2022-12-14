#ifndef ItemToPurchase_H_
#define ItemToPurchase_H_

#include <string>

using namespace std;

class ItemToPurchase {
private:
    string itemName;
    double itemPrice;
    int itemQuantity;
    string itemDescription;
public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, double price, int quantity);
    void SetName(string name);
    void SetPrice(double price);
    void SetQuantity(int quantity);
    void SetDescription(string description);
    string GetDescription();
    string GetName();
    double GetPrice();
    int GetQuantity();
    void PrintCostItem();
    void PrintDescription();
};


#endif
