#include "greyscale_filter.h"

//function to find the pixel value for greyscale fromt eh original pixel
float GetLuminance(unsigned char* pixel){
    return 0.2126*pixel[0] + 0.7152*pixel[1] + 0.0722*pixel[2];
}

void GreyScaleFilter::Apply(std::vector<Image*> original, std::vector<Image*> filter){
    *filter[0] = *original[0];
    for (int x=0; x<original[0]->GetWidth(); x++){
        for (int y=0; y<original[0]->GetHeight(); y++){

            //for loop that runs through all the pixels and finds their lum value

            unsigned char* oldPixel = original[0]->GetPixel(x,y);
            float lum = GetLuminance(oldPixel);  //gets the luinosity value of the pixel
            unsigned char newPixel[4] = {lum, lum, lum, 255}; //sets it to the filtered image
            filter[0]->SetPixel(x,y,newPixel);

        }
    }
}