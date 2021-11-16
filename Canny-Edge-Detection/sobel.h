#ifndef SOBEL_H_
#define SOBEL_H_
#include "filter.h"

class Sobel: public Filter{
    public:
        Sobel(){}
        void Apply(std::vector<Image*> original, std::vector<Image*> filter);
};

#endif