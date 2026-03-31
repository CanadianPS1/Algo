#include <iostream>
#include "../External/catch_amalgamated.hpp"
#include "../Testing/Test.h"
#include "../BubbleSort/BubbleSort.h"

/*

For the Test class

*/
//Checking if its adding correctly
TEST_CASE("Addition Correct Test"){
    Test test;
    REQUIRE(test.Addition(5, 10) == 15);
}
//Makes sure it isnt just outputing 15 every time
TEST_CASE("Addition Incorrect Test"){
    Test test;
    REQUIRE(test.Addition(5, 11) != 15);
}
//Checks if the var is nullptr so we know if it is existing
TEST_CASE("Addition Test"){
    Test* test = new Test();
    REQUIRE(test != nullptr);
    delete test;
}

/*

For Bubble Sort

*/

TEST_CASE("Bubble Sort Can Sort Array"){
    int arr[10] = {1,9,8,3,10,5,6,2,4,7};
    int arrSorted[10] = {1,2,3,4,5,6,7,8,9,10};
    BubbleSort bubble;
    bubble.Sort(&arr);
    REQUIRE(arr == arrSorted);
}
TEST_CASE("Can Handle Empty Array"){
    int arr[0] = {};
    int arrSorted[0] = {};
    BubbleSort bubble;
    bubble.Sort(arr*);
    REQUIRE(arr == arrSorted);
}