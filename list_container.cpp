#include "list_container.hpp"

/* Constructors */
ListContainer::ListContainer() : sort_function(nullptr)
{
    ;
}

/* Non Virtual Functions */
void ListContainer::set_sort_function(Sort* sort_function)
{
    this->sort_function = sort_function;
}

/* Virtual Functions */