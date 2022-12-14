//A Note regarding 'using namespace std':
// The author of this code prefers to not have the line 'using namespace std;'
// Instead, you will see 'std::' in front of string, cout, and other identifiers
// You could put 'using namespace std;' at the top of your code and not need 'std::' in front of these words,
// but many people consider it better practice to not have 'using namespace std;'

#include <iostream>
#include <string>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;

string GetUserString(const string& prompt);
double GetUserDouble(const string& prompt);
int GetUserInt(const string& prompt);



int main() {
    string customerName = GetUserString("Enter Customer's Name: ");
    string todayDate = GetUserString("Enter Today's Date: ");

    ShoppingCart userCart = ShoppingCart(customerName, todayDate);

    // .
    // This should be just one line of code that calls your ShoppingCart constructor

    string userMenuChoice = "none";
    bool continueMenuLoop = true;
    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter option: ");

        if (userMenuChoice == "add") {
            string itemName = GetUserString("Enter the item name: ");
            string itemDescription = GetUserString("Enter the item description: ");
            double itemPrice = GetUserDouble("Enter the item price: ");
            int itemQuantity = GetUserInt("Enter the item quantity: ");

            //TODO: Create an item and add it to the shopping cart
            ItemToPurchase newItem(itemName, itemDescription, itemPrice, itemQuantity);
            userCart.AddItem(newItem);

        }
        else if (userMenuChoice == "remove") {
            string nameOfItemToRemove = GetUserString("Enter name of the item to remove: ");

            //TODO: Remove the item from the shopping cart
            userCart.RemoveItem(nameOfItemToRemove);
        }
        else if (userMenuChoice == "change") {
            string nameOfItemToChange = GetUserString("Enter the item name: ");
            int newItemQuantity = GetUserInt("Enter the new quantity: ");

            userCart.UpdateQuantity(newItemQuantity, nameOfItemToChange);

        }
        else if (userMenuChoice == "descriptions") {
            //TODO: Print the information from the shopping cart
            userCart.PrintDescription();
        }
        else if (userMenuChoice == "cart") {
            //TODO: Print the information from the shopping cart
            userCart.PrintCost();
        }
        else if (userMenuChoice == "options") {
            cout << "MENU" << endl
                      << "add - Add item to cart" << endl
                      << "remove - Remove item from cart" << endl
                      << "change - Change item quantity" << endl
                      << "descriptions - Print the items' descriptions" << endl
                      << "cart - Print the shopping cart" << endl
                      << "options - Print the options menu" << endl
                      << "quit - Quit" << endl << endl;
        }
        else if (userMenuChoice == "quit") {
            cout << "Goodbye." << endl;
            continueMenuLoop = false;
        }
        else {
            cout << "MENU" << endl
                      << "add - Add item to cart" << endl
                      << "remove - Remove item from cart" << endl
                      << "change - Change item quantity" << endl
                      << "descriptions - Print the items' descriptions" << endl
                      << "cart - Print the shopping cart" << endl
                      << "options - Print the options menu" << endl
                      << "quit - Quit" << endl << endl;
        }
    }

    return 0;
}


string GetUserString(const string& prompt) {
    string userAnswer = "none";

    cout << prompt;
    getline(cin, userAnswer);
    cout << endl;
    return userAnswer;
}
double GetUserDouble(const string& prompt) {
    double userAnswer = 0.0;

    cout << prompt;
    cin >> userAnswer;
    cin.ignore();
    cout << endl;
    return userAnswer;
}
int GetUserInt(const string& prompt) {
    int userAnswer = 0;

    cout << prompt;
    cin >> userAnswer;
    cin.ignore();
    cout << endl;
    return userAnswer;
}

