
#ifndef CONTAINER_AND_SORT_TESTS_HPP
#define CONTAINER_AND_SORT_TESTS_HPP

#include "gtest/gtest.h"
#include "list_container.hpp"
#include "bubble_sort.hpp"
#include "op.hpp"
#include "add.hpp"
#include "vector_container.hpp"
#include "selection_sort.hpp"
#include "mult.hpp"


TEST(ListContainerTests, NoArgumentConstructor)
{
    Container* list = new ListContainer();
    
    EXPECT_EQ(list->size(), 0);
  
    EXPECT_THROW(
    try {
        list->sort();
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Uninitialized sort_function pointer", ia.what());
        throw;
    }, std::invalid_argument);
}


TEST(VectorContainerTests, DefaultConstructorTest) {
    Container* vc = new VectorContainer();
    
    EXPECT_EQ(vc->size(), 0);

    EXPECT_THROW(
    try {
        vc->sort();
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Uninitialized sort_function pointer", ia.what());
        throw;
    }, std::invalid_argument);
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

TEST(VectorContainerTests, ConstructorWithSelectionSortTest) {
    Container* vc = new VectorContainer(new SelectionSort());
    EXPECT_EQ(vc->size(), 0);
}

TEST(VectorContainerTests, AddOpElementTest) {
    Container* vc = new VectorContainer();
    Base* op = new Op(1);
    vc->add_element(op);
    EXPECT_EQ(vc->size(), 1);
}

TEST(VectorContainerTests, PrintTest) {
    Container* vc = new VectorContainer();
    Base* op1 = new Op(1);
    Base* op5 = new Op(5);
    Base* op8 = new Op(8);
    Base* op9 = new Op(9);
    Base* add = new Add(op1, op5);
    Base* mult = new Mult(op8, op9);
    Base* add2 = new Add(add, mult);


    vc->add_element(op1);
    vc->add_element(op5);
    vc->add_element(mult);
    vc->add_element(add2);

    vc->print();
}


TEST(VectorContainerTests, SwapTest) {
    Container* vc = new VectorContainer();
    Base* op0 = new Op(0);
    Base* op1 = new Op(1);
    Base* op2 = new Op(2);

    vc->add_element(op0);
    vc->add_element(op1);
    vc->add_element(op2);

    vc->swap(0, 2);

    EXPECT_EQ(vc->at(0)->evaluate(), 2);
    EXPECT_EQ(vc->at(1)->evaluate(), 1);
    EXPECT_EQ(vc->at(2)->evaluate(), 0);
}

TEST(VectorContainerTests, AtTest) {
    Container* vc = new VectorContainer();
    Base* op0 = new Op(0);
    Base* op1 = new Op(1);
    Base* op2 = new Op(2);

    vc->add_element(op0);
    vc->add_element(op1);
    vc->add_element(op2);

    EXPECT_EQ(vc->at(0)->evaluate(), 0);
    EXPECT_EQ(vc->at(1)->evaluate(), 1);
    EXPECT_EQ(vc->at(2)->evaluate(), 2);

    EXPECT_THROW(
    try {
        vc->at(3);
    }
    catch (std::out_of_range& oor) {
        EXPECT_STREQ("vector::_M_range_check: __n (which is 3) >= this->size() (which is 3)", oor.what());
        throw;
    }, std::out_of_range);
}

TEST(VectorContainerTests, SizeTest) {
    Container* vc = new VectorContainer();

    EXPECT_EQ(vc->size(), 0);    

    Base* op0 = new Op(0);
    Base* op1 = new Op(1);
    Base* op2 = new Op(2);  

    vc->add_element(op0);

    EXPECT_EQ(vc->size(), 1);  

    vc->add_element(op1);

    EXPECT_EQ(vc->size(), 2);  
    
    vc->add_element(op2);

    EXPECT_EQ(vc->size(), 3);  
}

#endif // CONTAINER_AND_SORT_TESTS_HPP
