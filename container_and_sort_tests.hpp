#ifndef __CONTAINER_AND_SORT_TESTS_HPP__
#define __CONTAINER_AND_SORT_TESTS_HPP__

#include "gtest/gtest.h"
#include "vector_container.hpp"
#include "selection_sort.hpp"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"


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
    EXPECT_EQ(vc->size(), 0);
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

#endif // __CONTAINER_AND_SORT_TESTS_HPP__