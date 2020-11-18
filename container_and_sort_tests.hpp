#ifndef CONTAINER_AND_SORT_TESTS_HPP
#define CONTAINER_AND_SORT_TESTS_HPP

#include "gtest/gtest.h"
#include "list_container.hpp"
#include "bubble_sort.hpp"
#include "op.hpp"
#include "add.hpp"

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

TEST(ListContainerTests, Print)
{
    Sort* sort_function = new BubbleSort();
    Container* list = new ListContainer(sort_function);

    Base* oneOp = new Op(1);
    Base* twoOp = new Op(2);
    Base* add = new Add(oneOp, twoOp);

    list->add_element(oneOp);
    list->add_element(add);
    list->add_element(twoOp);

    list->print();
}

TEST(ListContainerTests, At)
{
    Sort* sort_function = new BubbleSort();
    Container* list = new ListContainer(sort_function);

    Base* oneOp = new Op(1);
    Base* twoOp = new Op(2);
    Base* add = new Add(oneOp, twoOp);

    list->add_element(oneOp);
    list->add_element(add);
    list->add_element(twoOp);

    EXPECT_EQ(list->at(0)->evaluate(), 1);
    EXPECT_EQ(list->at(1)->evaluate(), 3);
    EXPECT_EQ(list->at(2)->evaluate(), 2);

    EXPECT_THROW(
        try{
            list->at(5);
        }
        catch (std::out_of_range& error) {
            EXPECT_STREQ("Out of range", error.what());
            throw;
        }
    , std::out_of_range);
}

TEST(ListContainerTests, Swap)
{
    Sort* sort_function = new BubbleSort();
    Container* list = new ListContainer(sort_function);

    Base* oneOp = new Op(1);
    Base* twoOp = new Op(2);
    Base* add = new Add(oneOp, twoOp);

    list->add_element(oneOp);
    list->add_element(add);
    list->add_element(twoOp);

    list->swap(1, 2);

    EXPECT_EQ(list->at(0)->evaluate(), 1);
    EXPECT_EQ(list->at(1)->evaluate(), 2);
    EXPECT_EQ(list->at(2)->evaluate(), 3);
}

TEST(ListContainerTests, SizeFunction)
{
    Sort* sort_function = new BubbleSort();
    Container* list = new ListContainer(sort_function);

    Base* oneOp = new Op(1);

    for (int i = 1; i <= 12; ++i)
        list->add_element(oneOp);
    EXPECT_EQ(list->size(), 12);
}

#endif // CONTAINER_AND_SORT_TESTS_HPP