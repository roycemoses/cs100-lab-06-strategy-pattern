#ifndef CONTAINER_AND_SORT_TESTS_HPP
#define CONTAINER_AND_SORT_TESTS_HPP

#include "gtest/gtest.h"
#include "list_container.hpp"
#include "bubble_sort.hpp"

TEST(ListContainerTests, NoArgumentConstructor)
{
    Container* list = new ListContainer();
    EXPECT_TRUE(list->sort_function == nullptr);
}

#endif // CONTAINER_AND_SORT_TESTS_HPP