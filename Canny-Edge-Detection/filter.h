#ifndef FILTER_H_
#define FILTER_H_
#include "image.h"

// Polymorphic class for all the other filters

class Filter{
    public: 
        virtual void Apply(std::vector<Image*> original, std::vector<Image*> filter) = 0;
};

#endif