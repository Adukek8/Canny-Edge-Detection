#ifndef DOUBLE_THRESHOLD_H_
#define DOUBLE_THRESHOLD_H_

#include <iostream>
#include <vector>
#include "filter.h"
#include "image.h"

class Double_threshold : public Filter{
    public:
        Double_threshold(float lowThresholdRatio, float highThresholdRatio);
    
        float max(std::vector<Image*> original);

        float getLuminance(unsigned char* pixel);

        virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
    
    private:
        // Threshold values for low and high
        float lowThresh,highThresh;
};

#endif