#ifndef GREYSCALE_H_
#define GREYSCALE_H_
#include "filter.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The Greyscale class is to use the Apply method, in this case to set image pixels to black and white
 *
 * makes use of luminances to determine the final pixel value
 */

class GreyScaleFilter: public Filter{
    public:
        /**
        * @brief Override of Apply method in Filter
        */   
        GreyScaleFilter(){}
        void Apply(std::vector<Image*> original, std::vector<Image*> filter);
};

#endif