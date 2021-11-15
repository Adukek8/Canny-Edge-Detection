/**
 * @file double_threshold.cc
 *
 * @copyright 2021 Ethan Pearson, All rights reserved.
 */

/*******************************************************************************
* Includes
******************************************************************************/

#include "canny_edge_detect.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>

#include "image.h"
#include "filter.h"
#include "greyscale_filter.h"
#include "gaussian.h"
#include "sobel.h"
#include "non-max_suppression_filter.h"
#include "double_threshold.h"
#include "hysteresis_filter.h"
#include "canny_edge_detect.h"


void CannyEdgeDetect::Apply(std::vector<Image*> og, std::vector<Image*> filtered){
    
    // create filters:
    std::map<std::string, unique_ptr<Filter>> filters;
    filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    filters["gaussian_blur"] = unique_ptr<Filter>(new Gaussian());
    filters["sobel_filter"] = unique_ptr<Filter>(new Sobel()); 
    filters["non_max_suppression"] = unique_ptr<Filter>(new NonMaxSuppression());
    filters["double_threshold"] = unique_ptr<Filter>(new Double_threshold(0.1,0.2));
    filters["hysteresis"] = unique_ptr<Filter>(new Hysteresis_filter());
    
    // get intensity and direction for later
    Image inten(og[0]->GetWidth(),og[0]->GetHeight());
    Image dir(og[0]->GetWidth(),og[0]->GetHeight());

    // two outputs for swapping for saving results
    Image output(og[0]->GetWidth(),og[0]->GetHeight());
    Image output2(og[0]->GetWidth(),og[0]->GetHeight());
    std::vector<Image*> inputs;
    std::vector<Image*> outputs;
    //inputs.push_back(&input);
    outputs.push_back(&output);


    // apply filters one at a time:
    filters["greyscale"]->Apply(og, outputs);

    outputs[0]->SaveAs("data/1.png");
    outputs.pop_back();
    inputs.push_back(&output);
    outputs.push_back(&output2);


    filters["gaussian_blur"]->Apply(inputs, outputs);
    
    outputs[0]->SaveAs("data/2.png");
    inputs.pop_back();
    outputs.pop_back();
    inputs.push_back(&output2);
    outputs.push_back(&inten);
    outputs.push_back(&dir);

    filters["sobel_filter"]->Apply(inputs, outputs);

    outputs[0]->SaveAs("data/3.png");
    outputs[1]->SaveAs("data/4.png");
    inputs.pop_back();
    outputs.pop_back();
    outputs.pop_back();
    inputs.push_back(&inten);
    inputs.push_back(&dir);
    outputs.push_back(&output2);


    filters["non_max_suppression"]->Apply(inputs, outputs);
    outputs[0]->SaveAs("data/5.png");

    inputs.pop_back();
    inputs.pop_back();
    outputs.pop_back();

    inputs.push_back(&output2);
    outputs.push_back(&output);

    filters["double_threshold"]->Apply(inputs, outputs);
    outputs[0]->SaveAs("data/6.png");

    inputs.pop_back();
    inputs.push_back(&output);

    filters["hysteresis"]->Apply(inputs, filtered);
}