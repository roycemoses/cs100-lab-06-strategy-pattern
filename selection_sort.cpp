#include "selection_sort.hpp"

void SelectionSort::sort(Container* container)
{
    int minIndex = 0;
    Base* ptr;
    for (int i = 0; i < container->size() - 1; ++i)
    {
        ptr = container->at(i);
        for (int j = i + 1; j < container->size(); ++j)
        {
            if (container->at(j)->evaluate() < ptr->evaluate())
            {
                minIndex = j;
                ptr = container->at(j);
            }
        }
        container->swap(i, minIndex);
    }
}