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

// TEST(VectorContainerTests, AtAfterDefaultConstructorTest) {
//     Container* vc = new VectorContainer();
//     EXPECT_THROW(
//     try {
//         vc->at(0);
//     }
//     catch (std::out_of_range& ofr) {
//         EXPECT_STREQ("Uninitialized sort_function pointer", ofr.what());
//         throw;
//     }, std::out_of_range);
//     EXPECT_EQ(vc->size(), 0);
// }


#endif // __CONTAINER_AND_SORT_TESTS_HPP__