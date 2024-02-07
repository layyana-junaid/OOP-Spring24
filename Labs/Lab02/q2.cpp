/*
 *Programmer: Layyana Junaid
 *Date: 6th Feb 2023
 *Description: Library Management system
 */

#include <iostream>
#include <string>
using namespace std;

// struct to store the details for each books
struct book
{
    string title;
    string author;
    int year_publication;
    string genre;
};

// function to print the data of the book
void print_book(const book& book) {
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Year of publication: " << book.year_publication << endl;
    cout << "Genre: " << book.genre << endl;
} // end of function

// function to search books by its title or author 
void find_book(const book books[], int n, const string& search_query) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (books[i].title == search_query || books[i].author == search_query) {
            cout << "Book Found: " << endl;
            print_book(books[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
} // end of function 

int main(int argc, char const* argv[])
{
    book books[100];
    int count = 0;
    int choice; // user input value for the switch cases

    do {
        cout << "Library Management System" << endl;
        cout << "Menu: " << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Search a book" << endl;
        cout << "3. Exit System" << endl;
        cout << "What do you want to do?(Enter the respective number): " << endl;
        cin >> choice;

        switch (choice) {

        case 1: {
            // adding a new book
            cout << "Enter book details:" << endl;
            cout << "Title: ";
            cin.ignore(); // Ignore the newline character left in the buffer
            getline(cin, books[count].title);
            cout << "Author: ";
            getline(cin, books[count].author);
            cout << "Year of Publication: ";
            cin >> books[count].year_publication;
            cout << "Genre: ";
            cin.ignore();
            getline(cin, books[count].genre);
            count++;
            cout << "Book added successfully!" << endl;
            break;
        }

        case 2: {
            // searching a book
            string search_query;
            cout << "Enter the title or author of the book you are searching for: ";
            cin.ignore();
            getline(cin, search_query);
            find_book(books, count, search_query);
            break;
        }

        case 3:
            // exiting the program
            cout << "Thank you for Searching!" << endl;
            break;

        default:
            cout << "Invalid Choice! Please press the possible choice!" << endl;
        }

    } while (choice != 3);

    return 0;
} // end main
