/**
 * @file hysteresis_filter.cc
 *
 * @copyright 2021 Calvin Hoffmann, All rights reserved.
 */

/*******************************************************************************
* Includes
******************************************************************************/

#include <iostream>
#include <vector>
#include "filter.h"
#include "image.h"
#include "hysteresis_filter.h"


/*******************************************************************************
 * Member Functions
 ******************************************************************************/

float Hysteresis_filter::getLuminance(unsigned char* pixel){
    return 0.2126*pixel[0] + 0.7152*pixel[1] + 0.0722*pixel[2];
}


void Hysteresis_filter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
    *filtered[0] = *original[0];        // copy original image to filtered image before convolution is applied

    unsigned char edge[4] = {0,0,0,0};              // blank pixel for pixels beyond edge of image
    unsigned char zero[4] = {0, 0, 0, 255};         // black pixel for zero pixels
    unsigned char weak[4] = {25, 25, 25, 255};      // weak pixel
    unsigned char strong[4] = {255, 255, 255, 255}; // strong pixel
    
    for(int x = 0; x < original[0]->GetWidth(); x++){           // outer x
        for(int y = 0; y < original[0]->GetHeight(); y++){      // outer y

            // if current pixel is weak, check neighbors
            if(getLuminance(original[0]->GetPixel(x,y)) == getLuminance(weak)){
                bool set = false;

                for(int InX = x-1; InX < x+1; InX++){      // inner x
                    for(int InY = y-1; InY < y+1; InY++){  // inner y
                        
                        // Outside bounds of image
                        if(InX < 0 || InY < 0 || InX > original[0]->GetWidth() || InY > original[0]->GetHeight()){
                            filtered[0]->SetPixel(InX, InY, edge);
                        }
                        // if a neighbor is strong, set the original pixel to strong
                        if(getLuminance(original[0]->GetPixel(InX, InY)) == getLuminance(strong)){
                            filtered[0]->SetPixel(x,y, strong);
                            set = true;     //indicate that the original had a strong neighbor and is now strong
                        }
                        // if the current pixel has no strong neighbors, set it to zero.
                        if(!set){
                            filtered[0]->SetPixel(x,y, zero);
                        }

                    }
                }
            }
            // If the current pixel is not weak, check if it is strong or zero.
            // If it is either of those, keep them as they are.
            else if(getLuminance(original[0]->GetPixel(x,y)) == getLuminance(strong)){
                filtered[0]->SetPixel(x,y, strong);
            }

            else if(getLuminance(original[0]->GetPixel(x,y)) == getLuminance(zero)){
                filtered[0]->SetPixel(x,y, zero);
            }

        }
    }
}
