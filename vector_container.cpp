#include "vector_container.hpp"

/* Constructors */
VectorContainer::VectorContainer() : sort_function(nullptr) { }

VectorContainer::VectorContainer(Sort* function) : sort_function(function) { }

/* Non Virtual Functions */
void VectorContainer::set_sort_function(Sort* sort_function) { this->sort_function = sort_function; }

/* Virtual Functions */
// push the top pointer of the tree into container
void VectorContainer::add_element(Base* element) { this->v.push_back(element); }

// iterate through trees and output the expressions (use stringify())
void VectorContainer::print() { for(int i = 0; i < v.size(); ++i) { v.at(i)->stringify(); } }

// calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
void VectorContainer::sort() { if (this->sort_function == nullptr) { throw; } this->sort_function->sort(this); }