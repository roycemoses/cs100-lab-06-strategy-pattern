#ifndef __CONTAINER_AND_SORT_TESTS_HPP__
#define __CONTAINER_AND_SORT_TESTS_HPP__

#include "gtest/gtest.h"
#include "vector_container.hpp"
#include "selection_sort.hpp"


TEST(VectorContainerTests, DefaultConstructorVCSizeTest) {
    Container* vc = new VectorContainer();
    EXPECT_EQ(vc->size(), 0);
}


// TEST(VectorContainerTest, SortAfterDefaultConstructorTest) {
//     Container* vc = new VectorContainer();
//     std::string error = "Uninitialized sort_function pointer";
//     EXPECT_ANY_THROW({
//         try {
//             vc->sort();
//         }
//         catch (char** str[])
//         {
//             EXPECT_STREQ(error, str);
//             throw;
//         }
//     });
// }

#endif // __CONTAINER_AND_SORT_TESTS_HPP__