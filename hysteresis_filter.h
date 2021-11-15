/**
 * @file hysteresis_filter.h
 *
 * @copyright 2021 Calvin Hoffmann, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#ifndef HYSTERESIS_FILTER_H_
#define HYSTERESIS_FILTER_H_

#include <iostream>
#include <vector>
#include "filter.h"
#include "image.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class which completes the hysteresis convolution.
 *
 */

class Hysteresis_filter : public Filter{
    public:        
     /**
     * @brief Calculates the luminance of a given pixel.
     *
     * @return Float value of the luminance of a pixel.
     */
        float getLuminance(unsigned char* pixel);

     /**
     * @brief Applies the hysteresis filter to the provided image and creates a new convoluted image.
     */
        virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered);

};

#endif