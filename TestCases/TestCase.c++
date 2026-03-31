#include <iostream>
#include "../External/catch_amalgamated.hpp"
#include "../Testing/Test.h"
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