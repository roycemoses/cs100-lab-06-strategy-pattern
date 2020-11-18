#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"

#include "vector_container.hpp"
#include "list_container.hpp"
#include "bubble_sort.hpp"
#include "selection_sort.hpp"

// g++ .\main.cpp .\list_container.cpp .\selection_sort.cpp .\vector_container.cpp

int main() {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);



    Container* vc1 = new VectorContainer();
    Container* vc2 = new VectorContainer();

    std::cout << "______VectorContainer______ " << std::endl;

    std::cout << "Size of VectorContainer1: " << vc1->size() << std::endl << std::endl;
    std::cout << "Size of VectorContainer2: " << vc2->size() << std::endl << std::endl;

    std::cout << "Adding elements to VectorContainer1..." << std::endl << std::endl;
    vc1->add_element(minus);
    vc1->add_element(seven);
    vc1->add_element(mult);
    vc1->add_element(two);
    vc1->add_element(add);
    vc1->add_element(four);
    vc1->add_element(three);

    std::cout << "Adding elements to VectorContainer2..." << std::endl << std::endl;
    vc2->add_element(minus);
    vc2->add_element(seven);
    vc2->add_element(mult);
    vc2->add_element(two);
    vc2->add_element(add);
    vc2->add_element(four);
    vc2->add_element(three);

    std::cout << "Size of VectorContainer1: " << vc1->size() << std::endl << std::endl;
    std::cout << "Size of VectorContainer2: " << vc2->size() << std::endl << std::endl;


    std::cout << "~ Contents of VectorContainer1 ~" << std::endl;
    vc1->print();
    std::cout << std::endl;

    std::cout << "~ Contents of VectorContainer2 ~" << std::endl;
    vc2->print();
    std::cout << std::endl;

    vc1->set_sort_function(new BubbleSort());
    std::cout << "Sorting VectorContainer1 with Bubble Sort strategy..." << std::endl << std::endl;
    vc1->sort();

    vc2->set_sort_function(new SelectionSort());
    std::cout << "Sorting VectorContainer2 with Selection Sort strategy..." << std::endl << std::endl;
    vc2->sort();

    std::cout << "~ Contents of VectorContainer1 ~" << std::endl;
    vc1->print();
    std::cout << std::endl;

    std::cout << "~ Contents of VectorContainer2 ~" << std::endl;
    vc2->print();
    std::cout << std::endl;


    ////////////////////////

    std::cout << "______ListContainer______ " << std::endl;

    Container* lc1 = new ListContainer();
    Container* lc2 = new ListContainer();

    std::cout << "Size of ListContainer1: " << lc1->size() << std::endl << std::endl;
    std::cout << "Size of ListContainer2: " << lc2->size() << std::endl << std::endl;

    std::cout << "Adding elements to ListContainer1..." << std::endl << std::endl;
    lc1->add_element(minus);
    lc1->add_element(seven);
    lc1->add_element(mult);
    lc1->add_element(two);
    lc1->add_element(add);
    lc1->add_element(four);
    lc1->add_element(three);


    std::cout << "Adding elements to ListContainer2..." << std::endl << std::endl;
    lc2->add_element(minus);
    lc2->add_element(seven);
    lc2->add_element(mult);
    lc2->add_element(two);
    lc2->add_element(add);
    lc2->add_element(four);
    lc2->add_element(three);

    std::cout << "Size of ListContainer1: " << lc1->size() << std::endl << std::endl;
    std::cout << "Size of ListContainer2: " << lc2->size() << std::endl << std::endl;

    std::cout << "~ Contents of ListContainer1 ~" << std::endl;
    lc1->print();
    std::cout << std::endl;

    std::cout << "~ Contents of ListContainer2 ~" << std::endl;
    lc2->print();
    std::cout << std::endl;

    lc1->set_sort_function(new BubbleSort());
    std::cout << "Sorting ListContainer1 with Bubble Sort Strategy..." << std::endl << std::endl;
    lc1->sort();

    lc2->set_sort_function(new SelectionSort());
    std::cout << "Sorting ListContainer2 with Selection Sort Strategy..." << std::endl << std::endl;
    lc2->sort();

    std::cout << "~ Contents of ListContainer1 ~" << std::endl;
    lc1->print();
    std::cout << std::endl;

    std::cout << "~ Contents of ListContainer2 ~" << std::endl;
    lc2->print();
    std::cout << std::endl;

    return 0;
}
