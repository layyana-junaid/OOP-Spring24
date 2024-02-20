#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    string name;
    string author;
    string ISBNnumb;
    int totalPages;
    int pagesRead;

public:
    // Default constructor with member initialization list
    Book() : name("Default Book"), author("Default Author"), ISBNnumb("0000000000"), totalPages(1000), pagesRead(0) {}

    // Setter methods for updating attribute values
    void setName(string name) { this->name = name; }
    void setAuthor(string author) { this->author = author; }
    void setISBN(string ISBN) { this->ISBNnumb = ISBN; }
    void setTotalPages(int totalPages) { this->totalPages = totalPages; }
    void setPagesRead(int pagesRead) { this->pagesRead = pagesRead; }

    // Method to update pages read and display message
    void updatePagesRead(int pages)
    {
        pagesRead += pages;
        if (pagesRead >= totalPages)
        {
            cout << "Congratulations! You have finished reading the book." << endl;
        }
        else
        {
            cout << "You have read " << pagesRead << " pages. You have " << totalPages - pagesRead << " pages left to read." << endl;
        }
    }

    // Method to display book information
    void showBookInfo()
    {
        cout << "Book Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBNnumb << endl;
        cout << "Total Pages: " << totalPages << endl;
        cout << "Pages Read: " << pagesRead << endl;
    }
};

int main()
{
    Book book;
    book.setName("");
    book.setAuthor("");
    book.setISBN("");

    book.updatePagesRead(0); // Reading 150 pages
    book.showBookInfo();

    return 0;
}
