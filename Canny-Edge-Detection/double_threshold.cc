#include <iostream>
#include <vector>
#include "filter.h"
#include "image.h"
#include "double_threshold.h"

Double_threshold::Double_threshold(float lowThresholdRatio, float highThresholdRatio){
    this->lowThresh = lowThresholdRatio;        // set low threshold value
    this->highThresh = highThresholdRatio;      // set high threshold value
}

float Double_threshold::getLuminance(unsigned char* pixel){
    return 0.2126*pixel[0] + 0.7152*pixel[1] + 0.0722*pixel[2];
}

float Double_threshold::max(std::vector<Image*> original){
    unsigned char max_pix[4] = {0,0,0,255}; // create a blank pixel to store maximum value
    int max_val;                            // maximum pixel value. Integer between 0-255
    for(int x = 0; x < original[0]->GetWidth(); x++){
        for(int y = 0; y < original[0]->GetHeight(); y++){
            if(original[0]->GetPixel(x,y)[0] > max_val){    // check if current pixel has a value greater than max
                max_val = original[0]->GetPixel(x,y)[0];    // set max val if greater
            }
        }
    }
    max_pix[0] += max_val;      // adjust max_pix to largest pixel. RGB will all be the same due to being in BW.
    max_pix[1] += max_val;
    max_pix[2] += max_val;
    
    return getLuminance(max_pix);       // return luminance of maximum pixel
} 

void Double_threshold::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
    
    float highThreshold = max(original) * highThresh;   // create high threshold value based on inputed ratio and max of image
    float lowThreshold = highThreshold * lowThresh;     // create low threshold value based on inputed ratio and max threshold

    unsigned char zero[4] = {0, 0, 0, 255};
    unsigned char weak[4] = {25, 25, 25, 255};
    unsigned char strong[4] = {255, 255, 255, 255};
    
    for(int x = 0; x < original[0]->GetWidth(); x++){
        for(int y = 0; y < original[0]->GetHeight(); y++){

            //strong
            if(getLuminance(original[0]->GetPixel(x,y)) > highThreshold){
                filtered[0]->SetPixel(x,y, strong);
            }

            //weak
            else if(getLuminance(original[0]->GetPixel(x,y)) < highThreshold && getLuminance(original[0]->GetPixel(x,y)) > lowThreshold){
                filtered[0]->SetPixel(x,y, weak);
            }

            //zeroes
            else{
                filtered[0]->SetPixel(x,y, zero);
            }

        }
    }
}
