#ifndef NIGHTVISION_H_
#define NIGHTVISION_H_
#include "filter.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Changes everything a hue of green better for human eye
 *
 */

class NightVision: public Filter{
    public:
        NightVision(){}
        void Apply(std::vector<Image*> original, std::vector<Image*> filter);
};

#endif