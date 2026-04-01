#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include "../External/catch_amalgamated.hpp"
#include "../Testing/Test.h"
#include "../BubbleSort/BubbleSort.h"
#include <bits/stdc++.h>
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
    std::vector<int> arrSorted = {1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    for(int i = arr.size() - 1; i >= 0; i--){
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    BubbleSort<int> bubble;
    arr = bubble.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<"nanoseconds";
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}
TEST_CASE("Can Handle Empty Array"){
    std::vector<int> arr = {};
    std::vector<int> arrSorted = {};
    BubbleSort<int> bubble;
    bool arraySorted = true;
    arr = bubble.Sort(arr);
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}