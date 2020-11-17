#include "selection_sort.hpp"

void SelectionSort::sort(Container* container)
{
    int min = 0;
    Base* min_ptr = container->at(0);
    for (int i = 0; i < container->size() - 2; ++i)
    {
        for (int j = i + 1; j < container->size() - 1; ++j)
        {
            if (container->at(i)->evaluate() < min_ptr->evaluate())
            {
                min = j;
                min_ptr = container->at(i);
            }
        }
        container->swap(i, min);
    }
}