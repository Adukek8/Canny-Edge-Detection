/**
 * @file sharpen_filter.h
 *
 * @copyright 2021 Ethan Pearson, All rights reserved.
 */

#ifndef SHARPEN_FILTER_H
#define SHARPEN_FILTER_H


/*******************************************************************************
* Includes
******************************************************************************/
#include "filter.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The Sharpen class is to use the Apply method, in this case to sharpen
 *
 *  Makes use of a matrix of values to enhance edges in the final image
 */
class Sharpen : public Filter {
    public:

 /**
  * @brief default constructor to do nothing
  *
  * @return no return value
  */
    Sharpen(){}

 /**
  * @brief Applies the Sharpen filter
  *
  * @return no return value but modifies the inputted image
  */   
    void Apply(std::vector<Image*> original, std::vector<Image*> filter);

};

#endif