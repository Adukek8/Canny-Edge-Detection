#ifndef IMAGE_H_
#define IMAGE_H_

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Image{
    public:


        // Generation of an empty image is that is of size widthxheight
        Image(int width, int height);

        // Generation of an array of image from gicen file path
        Image(string filename);

        //copy constructor 
        Image(const Image& image);

        // deconstructor 
        ~Image();

        
        // @brief Saves image to the fiven file name
        void SaveAs(string filename);

        // Getter for Height of image
        int GetHeight();

        // Getter for Width of image
        int GetWidth();

        // Getter for component number of image 
        int GetComponentNum();

        // getter for pixel values in an image
        unsigned char* GetPixel(int x, int y);

        // Setter for for values of certain pixel in image of image
        void SetPixel(int x, int y, unsigned char* pixel);

        // equals operator override
        void operator=(const Image& image);

    private:
        int width, height, components; //width, height and number of components
        unsigned char *buffer; //buffer for the image
};

#endif 