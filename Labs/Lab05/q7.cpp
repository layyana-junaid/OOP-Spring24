/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 4th March 2023
 *Description: implement a restaurant ordering system that hold different classes
 */

#include <iostream>
#include <string>
#include <vector>

// Menu Item class
class MenuItem {
private:
    std::string foodName;
    float foodPrice;

public:
    MenuItem(std::string name, float price) : foodName(name), foodPrice(price) {}

    std::string getFoodName() const {
        return foodName;
    }

    float getFoodPrice() const {
        return foodPrice;
    }
};

// Menu class
class Menu {
private:
    std::vector<MenuItem> items;

public:
    void addItem(const MenuItem& item) {
        items.push_back(item);
    }

    void removeItem(int index) {
        if (index >= 0 && index < items.size()) {
            items.erase(items.begin() + index);
        }
    }

    void displayMenu() const {
        std::cout << "Menu:" << std::endl;
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << i + 1 << ". " << items[i].getFoodName() << " - Rs" << items[i].getFoodPrice() << std::endl;
        }
    }
};

// Order class
class Order {
private:
    std::vector<MenuItem> items;
    float totalPayment;

public:
    Order(const std::vector<MenuItem>& orderItems, float payment) : items(orderItems), totalPayment(payment) {}

    float getTotalPayment() const {
        return totalPayment;
    }
};

// Payment class
class Payment {
private:
    float amount;

public:
    Payment(float amt) : amount(amt) {}

    float getAmount() const {
        return amount;
    }
};

// Restaurant class
class Restaurant {
private:
    Menu menu;

public:
    void addMenuItem(const MenuItem& item) {
        menu.addItem(item);
    }

    void removeMenuItem(int index) {
        menu.removeItem(index);
    }

    void displayMenu() const {
        menu.displayMenu();
    }

    Order placeOrder(const std::vector<MenuItem>& orderItems, float paymentAmount) {
        return Order(orderItems, paymentAmount);
    }
};

int main() {
    // Create a restaurant
    Restaurant restaurant;

    // Add menu items
    restaurant.addMenuItem(MenuItem("Burger", 450.55));
    restaurant.addMenuItem(MenuItem("Pizza", 2300.0));
    restaurant.addMenuItem(MenuItem("Salad", 396.99));

    // Display the menu
    restaurant.displayMenu();

    // Place an order
    std::vector<MenuItem> orderItems = { MenuItem("Burger", 450.55), MenuItem("Salad", 396.99) };
    Order order = restaurant.placeOrder(orderItems, 847.54);

    // Display the total payment for the order
    std::cout << "Total payment for the order: Rs" << order.getTotalPayment() << std::endl;

    return 0;
}

