#include "vector_container.hpp"

/* Constructors */
VectorContainer::VectorContainer() : sort_function(nullptr) { }

VectorContainer::VectorContainer(Sort* function) : sort_function(function) { }

/* Non Virtual Functions */
void VectorContainer::set_sort_function(Sort* sort_function) { this->sort_function = sort_function; }
