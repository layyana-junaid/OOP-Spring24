/*
 *Programmer: Layyana Junaid 
 *Date: 11th February 2024
 *Description: Creating a a class to store the stationery information 
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class StationaryShop {
private:
    static const int MAX_ITEMS = 100;
    string itemList[MAX_ITEMS];
    double itemPrices[MAX_ITEMS];
    int itemCount;

public:
    StationaryShop() : itemCount(0) {}

    // Function to add items and their prices
    void addItem(const string& itemName, double itemPrice) {
        if (itemCount < MAX_ITEMS) {
            itemList[itemCount] = itemName;
            itemPrices[itemCount] = itemPrice;
            cout << "Item '" << itemName << "' added successfully.\n";
            itemCount++;
        } else {
            cout << "Maximum items limit reached. Cannot add more items.\n";
        }
    }

    // Function to retrieve the list of items
    void displayItems() const {
        cout << "List of Items:\n";
        for (int i = 0; i < itemCount; ++i) {
            cout << itemList[i] << " - $" << fixed << setprecision(2) << itemPrices[i] << endl;
        }
    }

    // Function to modify the prices of items
    void modifyItemPrice(const string& itemName, double newItemPrice) {
        for (int i = 0; i < itemCount; ++i) {
            if (itemList[i] == itemName) {
                itemPrices[i] = newItemPrice;
                cout << "Price of item '" << itemName << "' modified successfully.\n";
                return;
            }
        }
        cout << "Item '" << itemName << "' not found.\n";
    }

    // Function to generate a receipt
    void generateReceipt(const string purchasedItems[][2], int purchasedItemCount) const {
        double totalAmount = 0.0;
        cout << "Receipt:\n";
        for (int i = 0; i < purchasedItemCount; ++i) {
            const string& itemName = purchasedItems[i][0];
            int quantity = stoi(purchasedItems[i][1]);
            double itemPrice = getItemPrice(itemName);
            cout << itemName << " x" << quantity << " - $" << fixed << setprecision(2) << quantity * itemPrice << endl;
            totalAmount += quantity * itemPrice;
        }
        cout << "Total: $" << fixed << setprecision(2) << totalAmount << endl;
    }

    // Helper function to get price of an item
    double getItemPrice(const string& itemName) const {
        for (int i = 0; i < itemCount; ++i) {
            if (itemList[i] == itemName) {
                return itemPrices[i];
            }
        }
        return 0.0; // Return 0 if item not found
    }
};

int main() {
    StationaryShop shop;
    int userChoice;
    string itemName;
    double itemPrice;
    static const int MAX_PURCHASED_ITEMS = 100;
    string purchasedItems[MAX_PURCHASED_ITEMS][2]; // Array to store items bought by customer
    int purchasedItemCount = 0;

    do {
        cout << "\nStationary Shop Menu:\n";
        cout << "1. Add Item\n";
        cout << "2. Display Items\n";
        cout << "3. Modify Price\n";
        cout << "4. Generate Receipt\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                cout << "Enter item name: ";
                cin >> itemName;
                cout << "Enter price: $";
                cin >> itemPrice;
                shop.addItem(itemName, itemPrice);
                break;
            case 2:
                shop.displayItems();
                break;
            case 3:
                cout << "Enter item name: ";
                cin >> itemName;
                cout << "Enter new price: $";
                cin >> itemPrice;
                shop.modifyItemPrice(itemName, itemPrice);
                break;
            case 4:
                // Input items bought by customer
                purchasedItemCount = 0;
                cout << "Enter items bought by customer (item name and quantity, e.g., 'Pen 2', enter 'Done' to finish):\n";
                while (true) {
                    cin >> itemName;
                    if (itemName == "Done") break;
                    cin >> purchasedItems[purchasedItemCount][0]; // Item name
                    cin >> purchasedItems[purchasedItemCount][1]; // Quantity
                    purchasedItemCount++;
                }
                // Generate receipt
                shop.generateReceipt(purchasedItems, purchasedItemCount);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (userChoice != 5);

    return 0;
}
