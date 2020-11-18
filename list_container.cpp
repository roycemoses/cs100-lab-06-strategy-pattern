#include "list_container.hpp"
/* Constructors */
ListContainer::~ListContainer()
{
    delete [] list;
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

void ListContainer::print()
{
    for (int i = 0; i < sz; ++i)
        list[i]->stringify();
}

void ListContainer::sort()
{
    std::invalid_argument ia("Uninitialized sort_function pointer");

    if (sort_function == nullptr)
        throw ia;

    sort_function->sort(this);        
}

void ListContainer::swap(int i, int j)
{
    Base* temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

Base* ListContainer::at(int i)
{
    std::out_of_range error("Out of range");
    if (i < 0 || i > sz - 1)
        throw error;
    return list[i];
}

int ListContainer::size()
{
    return sz;
}