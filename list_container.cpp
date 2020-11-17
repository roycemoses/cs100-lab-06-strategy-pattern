#include "list_container.hpp"

/* Constructors */
ListContainer::ListContainer() : sort_function(nullptr)
{
    ;
}

ListContainer::ListContainer(Sort* function) : sort_function(function)
{
    sz = 0;
    capacity = 1;
    list = new Base*[capacity];
}

/* Non Virtual Functions */
void ListContainer::set_sort_function(Sort* sort_function)
{
    this->sort_function = sort_function;
}

/* Virtual Functions */