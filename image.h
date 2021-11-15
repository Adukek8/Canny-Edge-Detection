#ifndef IMAGE_H_
#define IMAGE_H_


/*******************************************************************************
* Includes
******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @brief The class for handling images as unsighned char array.
 */


class Image{
    public:

        /**
        * @brief Generation of an empty image is that is of size widthxheight
        *
        * @return Unisghned char array of size widthxheight
        */    
        Image(int width, int height);

        /**
        * @brief Generation of an array of image from gicen file path
        *
        * @return Unisghned char array with pixel values
        */    
        Image(string filename);

        /**
        * @brief Copy constructur
        *
        * @return Unisghned char array of the image that is being copied
        */ 
        Image(const Image& image);

        /**
        * @brief Deconstrusctor
        */ 
        ~Image();

        /**
        * @brief Saves image to the fiven file name
        *
        * @return Saved image into the given file name
        */ 
        void SaveAs(string filename);

        /**
        * @brief Getter for Height of image
        *
        * @return Height of image
        */ 
        int GetHeight();

        /**
        * @brief Getter for Width of image
        *
        * @return Width of image
        */ 
        int GetWidth();

        /**
        * @brief Getter for Component number of image
        *
        * @return Component number of image
        */ 
        int GetComponentNum();

        /**
        * @brief Getter for for values of certain pixel in image of image
        *
        * @return an adress to the value of 
        */ 
        unsigned char* GetPixel(int x, int y);

        /**
        * @brief Setter for for values of certain pixel in image of image
        */ 
        void SetPixel(int x, int y, unsigned char* pixel);

        /**
        * @brief Equals operator override
        *
        * @return Copies the image into the new image variable
        */ 
        void operator=(const Image& image);

    private:
        int width, height, components; //width, height and number of components
        unsigned char *buffer; //buffer for the image
};

#endif 