/*
 *Programmer: Layyana Junaid (23k0056)
 *Date: 17th March 2023
 *Description:Lab06 task2
 */

#include <iostream>
#include <cstring>

// creating an image class
class Image
{
private:
    int width;
    int height;
    float *data;

public:
    // constructor that initializes
    Image(int w, int h, float *imgdata) : width(w), height(h)
    {
        // memory allocation
        data = new float[width * height];
        // copying the provided image data
        std::memcpy(data, imgdata, width * height * sizeof(float));
    }

    // copy constructor
    Image(const Image &other)
        : width(other.width), height(other.height)
    {
        data = new float[width * height];
        std::memcpy(data, other.data, width * height * sizeof(float));
    }

    // destructor
    ~Image()
    {
        delete[] data; // deallocating memory
    }

    void Display()
    {
        std::cout << "Width: " << width << std::endl;
        std::cout << "Height: " << height << std::endl;
        std::cout << "Image Data: " << std::endl;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                std::cout << data[i * width + j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void UpdateData()
    {
        for (int i = 0; i < width * height; ++i)
        {
            if (data[i] <= 0)
            {
                data[i] = rand() % 255 + 1; // Random value between 1 and 255
            }
        }
    }
};

int main()
{
    // Sample image data
    float imageData[] = {1.0, -2.0, 3.0, 0.0, 5.0, 6.0};

    // Create an Image object with dimensions 2x3 and initialize it with sample data
    Image originalImage(2, 3, imageData);

    // Create a copy of the original image
    Image copiedImage = originalImage;

    // Display the data of both the original and copied images
    std::cout << "Original Image:" << std::endl;
    originalImage.Display();

    std::cout << "Copied Image:" << std::endl;
    copiedImage.Display();

    // Update the image data
    originalImage.UpdateData();

    // Display the data of both the original and copied images after updating
    std::cout << "Original Image after update:" << std::endl;
    originalImage.Display();

    std::cout << "Copied Image after update:" << std::endl;
    copiedImage.Display();

    return 0;
}
