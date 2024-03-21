/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 21 March 23
 *Description: Lab 8 Task 1 
*/

#include <iostream>
#include <string>

class Book
{
protected:
    std::string title;
    std::string author;
    std::string publisher;
public:
// constructor
    Book(std::string t, std::string a, std::string pub) : title(t), author(a), publisher(pub) {}

//display function
void Display() {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Publisher: " << publisher << std::endl;
}

};

//creating the derived class which will inherit from the book class
class FictionBook : public Book
{
private:
    std::string genres;
    std::string protagonist;
public:
//creating a constructor that initializes the attributes of both base class and derived class
    FictionBook(std::string t, std::string a, std::string pub, std::string g, std::string p)
            : Book(t, a, pub), genres(g), protagonist(p) {}
    
//display function
void Display() {
    std::cout << "Author: " << author << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Publisher: " << publisher << std::endl;
    std::cout << "Genre: " << genres << std::endl;
    std::cout << "Protagonist: " << protagonist << std::endl;
}    

};

int main(int argc, char const *argv[])
{
    FictionBook book1("Harry Potter and the Goblet of Fire", "JK Rowling", "Bloomsbury", "Fantasy", "Boy");
    book1.Display();

    return 0;
}


