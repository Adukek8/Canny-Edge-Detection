#ifndef GAUS_H_
#define GAUS_H_
#include "filter.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The Gasssian class is to use the Apply method, in this case to blur the original image
 *
 * multiplies each pixel by the gaussian kernal
 *
 */

class Gaussian: public Filter{
    public:

        /**
        * @brief Override of Apply method in Filter returns new filtered image
        */   
        Gaussian(){}
        void Apply(std::vector<Image*> original, std::vector<Image*> filter);
};

#endif