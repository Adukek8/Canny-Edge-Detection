#ifndef GREYSCALE_H_
#define GREYSCALE_H_
#include "filter.h"


// The Greyscale class is to use the Apply method, in this case to set image pixels to black and white
class GreyScaleFilter: public Filter{
    public:
        /**
        * @brief Override of Apply method in Filter
        */   
        GreyScaleFilter(){}
        void Apply(std::vector<Image*> original, std::vector<Image*> filter);
};

#endif