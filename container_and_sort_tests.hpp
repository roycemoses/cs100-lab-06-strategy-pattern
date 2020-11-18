#ifndef __CONTAINER_AND_SORT_TESTS_HPP__
#define __CONTAINER_AND_SORT_TESTS_HPP__

#include "gtest/gtest.h"
#include "vector_container.hpp"
#include "selection_sort.hpp"
#include "op.hpp"


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