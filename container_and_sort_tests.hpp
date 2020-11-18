#ifndef CONTAINER_AND_SORT_TESTS_HPP
#define CONTAINER_AND_SORT_TESTS_HPP

#include "gtest/gtest.h"
#include "list_container.hpp"
#include "bubble_sort.hpp"
#include "op.hpp"

TEST(ListContainerTests, NoArgumentConstructor)
{
    Container* list = new ListContainer();
    EXPECT_THROW(
    try {
        list->sort();
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Uninitialized sort_function pointer", ia.what());
        throw;
    }, std::invalid_argument);
    EXPECT_EQ(list->size(), 0);
}

TEST(ListContainerTests, ConstructorTestWithBubbleSortFunction)
{
    Sort* sort_function = new BubbleSort();
    Container* list = new ListContainer(sort_function);
    
    EXPECT_EQ(list->size(), 0);
}


TEST(ListContainerTests, AddElement)
{
    Sort* sort_function = new BubbleSort();
    Container* list = new ListContainer(sort_function);
    
    EXPECT_EQ(list->size(), 0);

    Base* twoOp = new Op(2);
    list->add_element(twoOp);
    EXPECT_EQ(list->size(), 1);

    list->add_element(twoOp);
    EXPECT_EQ(list->size(), 2);

}

#endif // CONTAINER_AND_SORT_TESTS_HPP