/*
 *Programmer: Layyana Junaid
 *Date: 6th Feb 2023
 *Description: Basic product management system
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// creating a struct to store the product details
struct Product
{
	string productName;
	double price;
	int quantity;
	string details;
	
};

//create a map to store products with their ids
unordered_map<int, Product>  products;

//function to  add new products
void addingProduct() {
	int productID;
	string productName;
	string details;
	int quantity;
	double price;

    // asking user to enter the new product data
    cout << "Enter the Product details:";
	cout << "Product ID: ";
	cin >> productID;
	cout << "Product Name: ";
	cin.ignore(); 
	getline(cin, productName);
	cout << "Product Price: ";
	cin >> price;
	cout << "Quantity of Product: ";
	cin >> quantity;
	cout << "Product Details: ";
	cin.ignore();
	getline(cin, details);

	products[productID] = {productName, price, quantity, details};
	cout << "Product has been added successfully!!" << endl;

} // end of adding function 


// function to display the information of a product using id
void displayProducts() {
	int productID;

	cout << "Enter product ID: ";
	cin >> productID;
    
    if (products.find(productID) != products.end()) {
        Product product = products[productID];
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << product.productName << endl;
        cout << "Price: $" << product.price << endl;
        cout << "Quantity in Stock: " << product.quantity << endl;
        cout << "Details: " << product.details << endl;
    } else {
        cout << "Product with ID " << productID << " not found." << endl;
    }

}// end of function 


// function to update product information using product id
void updateProduct() {
	int productID;
	double price;
	int quantity;
	string details;
    
    cout << "Enter product ID: ";
    cin >> productID;

    if (products.find(productID) != products.end()) {
        cout << "Enter new price: ";
        cin >> price;
        cout << "Enter new quantity: ";
        cin >> quantity;
        cout << "Enter new details: ";
        cin.ignore();
        getline(cin, details);

        products[productID].price = price;
        products[productID].quantity = quantity;
        products[productID].details = details;
        cout << "Product information updated successfully!" << endl;
    } else {
        cout << "Product with ID " << productID << " not found." << endl;
    }

}// end of function


int main() {

	int option;

	do {

		cout << "Product Management System:" << endl;
		cout << "1- Add a Product" << endl;
		cout << "2- Display Product Details" << endl;
		cout << "3- Update Product Information" << endl;
		cout << "4- Exit Program" << endl;
		cout << "Enter your option: " << endl;
		cin >> option; 

		switch (option) {
		case '1' :
			addingProduct();
			break;
		case '2' :
			displayProducts();
			break;
		case '3' :
			updateProduct();
			break;
		case '4' :
			cout << "Exiting the Program!" << endl;
			break;
		default :
			cout << "Invalid Option!! Choose the corret option." << endl;	
		}	
} while (option != 4);

 return 0;

} // end main 