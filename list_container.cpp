#include "list_container.hpp"

void ListContainer::set_sort_function(Sort* sort_function)
{
    this->sort_function = sort_function;
}