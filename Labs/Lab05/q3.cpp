/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 4th March 2023
 *Description: creating a class called validate string, the purpose is to check the given strings and
 tell if there are only string elements present in the string
 */

#include <iostream>
#include <string>

// creating a Validate string class

class ValidateString
{
private:
    std::string str;
public:
//parameterized Constructor
    ValidateString(const std::string& s) : str(s) {}

/*The const keyword in the isString function signifies that it does not 
alter the state of the ValidateString object. This allows the function 
to be called on const instances of ValidateString without modifying any member variables.*/
    bool isString() const{
        for(char c : str) {
            if(!isalpha(c)) {
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    ValidateString valid("laYYanaJunAId");
    ValidateString invalid("23k0056FAST");

    std::cout << "'laYYanaJunAId' is: " << (valid.isString() ? "Valid" : "Not Valid") << std::endl;
    std::cout << "'23k0056FAST' is: " << (invalid.isString() ? "Valid" : "Not Valid") << std::endl;
    return 0;
}
