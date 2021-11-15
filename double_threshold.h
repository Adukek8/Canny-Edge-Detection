/**
 * @file double_threshold.h
 *
 * @copyright 2021 Calvin Hoffmann, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#ifndef DOUBLE_THRESHOLD_H_
#define DOUBLE_THRESHOLD_H_

#include <iostream>
#include <vector>
#include "filter.h"
#include "image.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class which completes the double threshold convolution.
 *
 */

class Double_threshold : public Filter{
    public:
    /**
     * @brief Double threshold constructor to set values.
     */
        Double_threshold(float lowThresholdRatio, float highThresholdRatio);
    
    /**
     * @brief Loop to find maximum pixel luminance in an image.
     *
     * Calls to getLuminance in order to get the luminance value of the maximum pixel.
     * 
     * @return Float value of the luminance of the maximum pixel.
     */
        float max(std::vector<Image*> original);

    /**
     * @brief Double threshold constructor to set values.
     *
     * @return Float value of the luminance of a pixel.
     */
        float getLuminance(unsigned char* pixel);

     /**
     * @brief Applies the double threshold filter to the provided image and creates a new convoluted image.
     */
        virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
    
    private:
        // Threshold values for low and high
        float lowThresh,highThresh;
};

#endif