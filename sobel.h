#ifndef SOBEL_H_
#define SOBEL_H_
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The Greyscale class is to use the Apply method, in this case to set image pixels to black and white
 *
 * makes use of luminances to determine the final pixel value
 */
class Sobel: public Filter{
    public:
        /**
        * @brief Override of Apply method in Filter on an original photo and aediting two filter imamages of intesity and direction
        */   
        Sobel(){}
        void Apply(std::vector<Image*> original, std::vector<Image*> filter);
};

#endif