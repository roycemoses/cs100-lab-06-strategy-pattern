#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "container.hpp"

class Container;

class BubbleSort {
    public:
        /* Constructors */
        BubbleSort();

        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
};

#endif //__BUBBLE_SORT_HPP__
