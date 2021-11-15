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
#include "sharpen_filter.h"
#include "nightvision_filter.h"
#include "canny_edge_detect.h"

using namespace std;

int main(int argc, const char* argv[]) {
    // Get input file, filter type, and output file from command line
    // argc = # of arguments
    // argv = an array of arguments
    std::string inputFile(argv[1]);
    std::string filterType(argv[2]);
    std::string outputFile(argv[3]);




    // Create available filters (unique_ptr handles dynamic memory)
    std::map<std::string, unique_ptr<Filter>> filters;
    filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    filters["gaussian_blur"] = unique_ptr<Filter>(new Gaussian());
    filters["sobel_filter"] = unique_ptr<Filter>(new Sobel());    
    filters["non_max_suppression"] = unique_ptr<Filter>(new NonMaxSuppression()); 
    filters["double_threshold"] = unique_ptr<Filter>(new Double_threshold(0.1, 0.2));      
    filters["hysteresis"] = unique_ptr<Filter>(new Hysteresis_filter());
    filters["sharpen"] = unique_ptr<Filter>(new Sharpen());
    filters["night_vision"] = unique_ptr<Filter>(new NightVision());
    filters["canny-edge-detect"] = unique_ptr<Filter>(new CannyEdgeDetect());


    // Create input and output vectors
    Image input(inputFile);
    Image output(input.GetWidth(),input.GetHeight());
    Image output2(input.GetWidth(),input.GetHeight());
    std::vector<Image*> inputs;
    std::vector<Image*> outputs;
    inputs.push_back(&input);
    outputs.push_back(&output);
    outputs.push_back(&output2);
    // Apply filter based on filter type
    filters[filterType]->Apply(inputs, outputs);
    
    // Save output image
    output.SaveAs(outputFile);
}