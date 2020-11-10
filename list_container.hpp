#ifndef __LIST_CONTAINER_HPP__
#define __LIST_CONTAINER_HPP__

#include "container.hpp"

class ListContainer : public Container {
    protected:
        Sort* sort_function;

    public:
        /* Constructors */
        ListContainer() : sort_function(nullptr) { };
        ListContainer(Sort* function) : sort_function(function) { };

        /* Non Virtual Functions */
        void set_sort_function(Sort* sort_function); // set the type of sorting algorithm

        /* Virtual Functions */
        // push the top pointer of the tree into container
        virtual void add_element(Base* element);
        // iterate through trees and output the expressions (use stringify())
        virtual void print();
        // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
        virtual void sort();

        /* Essentially the only functions needed to sort */
        //switch tree locations
        virtual void swap(int i, int j);
        // get top ptr of tree at index i
        virtual Base* at(int i);
        // return container size
        virtual int size();
};

#endif //__LIST_CONTAINER_HPP__
