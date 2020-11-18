CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
    strategy_test.cpp
    vector_container.cpp
    list_container.cpp
    selection_sort.cpp
    bubble_sort.cpp
)

ADD_EXECUTABLE(main
    main.cpp
    vector_container.cpp
    list_container.cpp
    selection_sort.cpp
    bubble_sort.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)