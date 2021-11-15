#ifndef FILTER_H_
#define FILTER_H_
#include "image.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Polymorphic class for all the other filters
 *
 */


class Filter{
    public:
        //NONMAX
        // virtual void Apply(std::vector<Image*> original, std::vector<Image*> filter, std::vector<Image*> direction) = 0;
        /**
        * @brief Vritual method for all filter classes
        */    
        virtual void Apply(std::vector<Image*> original, std::vector<Image*> filter) = 0;
};

#endif