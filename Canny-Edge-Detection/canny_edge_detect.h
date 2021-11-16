/**
 * @file double_threshold.h
 *
 * @copyright 2021 Ethan Pearson, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#ifndef CANNY_EDGE_DETECT_H_
#define CANNY_EDGE_DETECT_H_

#include "filter.h"
#include <vector>
#include "image.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class which completes the full Canny Edge Detection.
 *
 */
class CannyEdgeDetect: public Filter {
    public:
    /**
     * @brief Canny Edge constructor to set values.
     */    
        CannyEdgeDetect(){}
    /**
     * @brief Runs 7 filters one after another.
     */
        void Apply(std::vector<Image*> original, std::vector<Image*> filter);
};

#endif