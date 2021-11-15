#include "non-max_suppression_filter.h"
#include <cmath>

void NonMaxSuppression::Apply(std::vector<Image*> original, std::vector<Image*> filter){
    *filter[0] = *original[0];
    unsigned char *pixel;
    unsigned char black[4] = {0,0,0,255};

    // for every pixel in the image
    for (int x = 0; x < original[0]->GetWidth(); x++){
        for (int y = 0; y < original[0]->GetHeight(); y++){
            int q = 255;
            int r = 255;

            unsigned char pixel_direction = original[1]->GetPixel(x, y)[0]; 

            // angle 0
            if (0 <= pixel_direction < 22.5 || 157.5 <= pixel_direction <= 180) {
                q = original[0]->GetPixel(x, y + 1)[0];
                r = original[0]->GetPixel(x, y - 1)[0];
            } else if (22.5 <= pixel_direction < 67.5) {   // angle 45
                q = original[0]->GetPixel(x + 1, y - 1)[0];
                r = original[0]->GetPixel(x - 1, y + 1)[0];
            } else if (67.5 <= pixel_direction < 112.5) {  // angle 90
                q = original[0]->GetPixel(x + 1, y)[0];
                r = original[0]->GetPixel(x - 1, y)[0];
            } else if (112.5 <= pixel_direction < 157.5) { // angle 135
                q = original[0]->GetPixel(x - 1, y - 1)[0];
                r = original[0]->GetPixel(x + 1, y + 1)[0];
            }

            //set least definite pixels to black
            if (original[0]->GetPixel(x, y)[0] >= q && original[0]->GetPixel(x, y)[0] >= r) {
                filter[0]->SetPixel(x, y, original[0]->GetPixel(x, y));
            } else {
                filter[0]->SetPixel(x, y, black);
            }
        }
    }
}