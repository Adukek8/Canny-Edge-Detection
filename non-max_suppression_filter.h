#ifndef NONMAX_H_
#define NONMAX_H_
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Filter that takes in direction and intensity images and finds the pixel with max value
 *
 */
class NonMaxSuppression: public Filter {
    public:
        NonMaxSuppression(){}
        void Apply(std::vector<Image*> original, std::vector<Image*> filter);
};

#endif