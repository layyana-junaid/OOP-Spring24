/*
 *Programmer: Layyana Junaid 
 *Date: 11th February 2024
 *Description: Creating a smartphone 
 */

#include <iostream>
#include <string>
using namespace std;

class Smartphone {
private:
    string brand;
    string model;
    string resolution;
    string Ram;
    string Rom;
    string storage;

public:
    string getBrand() const {
        return brand;
    }

    string getModel() const {
        return model;
    }

    string getResolution() const {
        return resolution;
    }

    string getRam() const {
        return Ram;
    }

    string getRom() const {
        return Rom;
    }

    string getStorage() const {
        return storage;
    }

    void setBrand(const string& brand) {
        this->brand = brand;
    }

    void setModel(const string& model) {
        this->model = model;
    }

    void setResolution(const string& resolution) {
        this->resolution = resolution;
    }

    void setRam(const string& Ram) {
        this->Ram = Ram;
    }

    void setRom(const string& Rom) {
        this->Rom = Rom;
    }

    void setStorage(const string& storage) {
        this->storage = storage;
    }

    void phonecalls(const string& number) const {
        cout << "Calling " << number << "....\n";
    }

    void message(const string& sendto, const string& message) const {
        cout << "Sending message to " << sendto << ": " << message << endl;
    }

    void Wifi(const string& wifiname, const string& password) const {
        cout << "Connecting to Wifi: " << wifiname << "...\n";
    }

    void internet(const string& url) const {
        cout << "Browsing the internet: " << url << "....\n";
    } 

    Smartphone() {}
    ~Smartphone() {}
};

int main(int argc, char const *argv[]) {
    Smartphone iphone; 
    iphone.setBrand("Apple");
    iphone.setModel("iphone 13");
    iphone.setResolution("2532 x 1170 pixels");
    iphone.setRam("6 GB");
    iphone.setRom("128 GB");
    iphone.setStorage("256 GB");

    cout << "iPhone Details: " << endl;
    cout << "Brand: " << iphone.getBrand() << endl;
    cout << "Model: " << iphone.getModel() << endl;
    cout << "Display Resolution: " << iphone.getResolution() << endl;
    cout << "RAM: " << iphone.getRam() << endl;
    cout << "ROM: " << iphone.getRom() << endl;
    cout << "Storage: " << iphone.getStorage() << endl;

    Smartphone samsung;
    samsung.setBrand("Samsung");
    samsung.setModel("Galaxy S21");
    samsung.setResolution("2400 x 1080 pixels");
    samsung.setRam("8 GB");
    samsung.setRom("128 GB");
    samsung.setStorage("256 GB");

    cout << "Samsung Details: " << endl;
    cout << "Brand: " << samsung.getBrand() << endl;
    cout << "Model: " << samsung.getModel() << endl;
    cout << "Display Resolution: " << samsung.getResolution() << endl;
    cout << "RAM: " << samsung.getRam() << endl;
    cout << "ROM: " << samsung.getRom() << endl;
    cout << "Storage: " << samsung.getStorage() << endl;

    iphone.phonecalls("123-456-789");
    iphone.message("Alex", "Hi, how are you?");
    iphone.Wifi("wifi", "passwordabcd");
    iphone.internet("www.google.com");

    samsung.phonecalls("123-456-789");
    samsung.message("Alex", "Hi, how are you?");
    samsung.Wifi("wifi", "passwordabcd");
    samsung.internet("www.google.com");

    return 0;
}
