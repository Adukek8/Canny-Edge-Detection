#ifndef HYSTERESIS_FILTER_H_
#define HYSTERESIS_FILTER_H_

#include <iostream>
#include <vector>
#include "filter.h"
#include "image.h"

class Hysteresis_filter : public Filter{
    public:        
       // Calculates the luminance of a given pixel.
        float getLuminance(unsigned char* pixel);

        // Applies the hysteresis filter to the provided image and creates a new convoluted image.
        virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered);

};

#endif