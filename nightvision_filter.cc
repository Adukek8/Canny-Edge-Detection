#include "nightvision_filter.h"

void NightVision::Apply(std::vector<Image*> original, std::vector<Image*> filter) {
    *filter[0] = *original[0];
    
    // loop through every pixel
    for (int i = 0; i < original[0]->GetWidth(); i++) {
        for (int j = 0; j < original[0]->GetHeight(); j++) {
            
            // determine RGB values of each pixel
            unsigned char* old = original[0]->GetPixel(i,j);

            // new pixel only contains G values
            unsigned char new_pixel[4] = {0, old[1], 0, 255};

            // set pixel value
            filter[0]->SetPixel(i, j, new_pixel);
            
        }
    }

}