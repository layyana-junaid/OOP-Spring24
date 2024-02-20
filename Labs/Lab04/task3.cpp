/*
 *Programmer: Layyana Junaid
 *Date: 15th Feb 2024
 *Description: Lab 4 Question 1 
 * 
 */

#include <iostream>
#include <string>

using namespace std;

// creating a class representing book
class Book
{
private:
    string name; // name of the book
    string author; // author of the book
    string ISBNnumb; // isbn number of book
    int totalPages;
    int pagesRead;
public:
    // default constructor
    Book() {
        this->name = "Default Book";
        this->author = "Default Author";
        this->ISBNnumb = "0000000000";
        this->totalPages = 0;
        this->pagesRead = 0;
    } 

    // parameterized constructor
    Book(string name, string author, string ISBNnumb, int totalPages, int pagesRead) {
        this->name = name;
        this->author = author;
        this->ISBNnumb = ISBNnumb;
        this->totalPages = totalPages;
        this->pagesRead = pagesRead;
    } 
    
    // creating a update page function;
    void updatePagesRead(int pages){
        pagesRead += pages;
        if(pagesRead > totalPages) {
            cout << "You have finished the book!" << endl;
        }
        else {
            cout << "You have read " << pagesRead << " pages. You have " << totalPages - pagesRead << " pages to read!" << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Book book("Charlie and the Chocolate Factory", "Roald Dahl", "494030220", 300, 150);
    book.updatePagesRead(80);
    return 0;
}

