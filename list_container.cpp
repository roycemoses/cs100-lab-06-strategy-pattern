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

void ListContainer::expand()
{
    capacity *= 2;
    Base** temp = new Base*[capacity];
    for (int i = 0; i < this->sz; ++i)
        temp[i] = list[i];
    delete [] list;
    list = temp;
}

/* Virtual Functions */
void ListContainer::add_element(Base* element)
{
    if (sz + 1 >= capacity)
        expand();
    list[sz] = element;
    sz += 1;
}