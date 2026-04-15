#include "../External/catch_amalgamated.hpp"
#include <iostream>
#include <vector>
//#include <chrono>
#include <algorithm>
#include <random>

#include "../Testing/Test.h"
#include "../BubbleSort/BubbleSort.h"
#include "../SelectionSort/SelectionSort.h"
#include "../InsertionSort/InsertionSort.h"
#include "../CubeSort/CubeSort.h"
#include "../LeetCode/LeetCode1.c++"
#include "../BinarySearch/BinarySearch.h"
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
    std::vector<int> arrSorted;
    int amount = 30;
    for(int i = 1; i <= amount; i++){
        arrSorted.push_back(i);
    }
    std::vector<int> arr = arrSorted;
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
    //std::cout<<"   Bubble Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}
TEST_CASE("Bubble Sort Can Handle 1 Item"){
    std::vector<int> arrSorted = {1};
    std::vector<int> arr = arrSorted;
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    BubbleSort<int> bubble;
    arr = bubble.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<"nanoseconds";
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


/*

Selection Sort

*/

TEST_CASE("Selection Sort Can Sort Array"){
    std::vector<int> arrSorted;
    int amount = 30;
    for(int i = 1; i <= amount; i++){
        arrSorted.push_back(i);
    }
    std::vector<int> arr = arrSorted;
    for(int i = arr.size() - 1; i >= 0; i--){
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        //std::cout<<"unsorted at ~"<<(i + 1)<<"~ : "<<arr[i]<<std::endl;
    }
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    SelectionSort<int> selection;
    arr = selection.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Selection Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}
TEST_CASE("Selection Sort Can Handle 1 Item"){
    std::vector<int> arrSorted = {1};
    std::vector<int> arr = arrSorted;
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    SelectionSort<int> selection;
    arr = selection.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Selection Sort Can Handle Empty Array"){
    std::vector<int> arr = {};
    std::vector<int> arrSorted = {};
    SelectionSort<int> selection;
    bool arraySorted = true;
    arr = selection.Sort(arr);
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Selection Sort Can Sort Array of the same value"){
    std::vector<int> arrSorted;
    int amount = 30;
    for(int i = 1; i <= amount; i++){
        arrSorted.push_back(1);
    }
    std::vector<int> arr = arrSorted;
    for(int i = arr.size() - 1; i >= 0; i--){
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        //std::cout<<"unsorted at ~"<<(i + 1)<<"~ : "<<arr[i]<<std::endl;
    }
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    SelectionSort<int> selection;
    arr = selection.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Selection Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}


TEST_CASE("Selection Sort Can Sort negitive Array"){
    std::vector<int> arrSorted;
    int amount = 30;
    for(int i = 1; i <= amount; i++){
        arrSorted.push_back(i - 100);
    }
    std::vector<int> arr = arrSorted;
    for(int i = arr.size() - 1; i >= 0; i--){
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        //std::cout<<"unsorted at ~"<<(i + 1)<<"~ : "<<arr[i]<<std::endl;
    }
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    SelectionSort<int> selection;
    arr = selection.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Selection Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}
/*

Insertion Sort

*/

TEST_CASE("Insertion Sort Can Sort Array"){
    std::vector<int> arrSorted;
    int amount = 10;
    for(int i = 1; i <= amount; i++){
        arrSorted.push_back(i);
    }
    std::vector<int> arr = arrSorted;
    for(int i = arr.size() - 1; i >= 0; i--){
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        //std::cout<<"unsorted at ~"<<(i + 1)<<"~ : "<<arr[i]<<std::endl;
    }
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    InsertionSort<int> insertion;
    arr = insertion.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Insertion Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}
TEST_CASE("Insertion Sort Can Handle 1 Item"){
    std::vector<int> arrSorted = {1};
    std::vector<int> arr = arrSorted;
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    InsertionSort<int> insertion;
    arr = insertion.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Insertion Sort Can Handle Empty Array"){
    std::vector<int> arr = {};
    std::vector<int> arrSorted = {};
    InsertionSort<int> insertion;
    bool arraySorted = true;
    arr = insertion.Sort(arr);
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Insertion Sort Can Sort Arrays of the same value"){
    std::vector<int> arrSorted;
    int amount = 30;
    for(int i = 1; i <= amount; i++){
        arrSorted.push_back(1);
    }
    std::vector<int> arr = arrSorted;
    for(int i = arr.size() - 1; i >= 0; i--){
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        //std::cout<<"unsorted at ~"<<(i + 1)<<"~ : "<<arr[i]<<std::endl;
    }
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    InsertionSort<int> insertion;
    arr = insertion.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Insertion Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Insertion Sort Can Sort negitive Arrays"){
    std::vector<int> arrSorted;
    int amount = 30;
    for(int i = 1; i <= amount; i++){
        arrSorted.push_back(i - 100);
    }
    std::vector<int> arr = arrSorted;
    for(int i = arr.size() - 1; i >= 0; i--){
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        //std::cout<<"unsorted at ~"<<(i + 1)<<"~ : "<<arr[i]<<std::endl;
    }
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    InsertionSort<int> insertion;
    arr = insertion.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Insertion Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}
/*

    Leet Code

*/


TEST_CASE("Checks if it finds the sum"){
    std::vector<int> arr = {3,2,4};
    std::vector<int> answer = {1,2};
    TwoSum twoSum;
    bool answered = true;
    arr = twoSum.twoSum(arr, 6);
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != answer[i]) answered = false;
    }
    REQUIRE(answered == true);
}
TEST_CASE("checks if it gives the write index"){
    int answer;
    AddTwoNumbers add;
    bool answered = false;
    answer = add.strStr("Grinch", "r");
    if(answer == 1) answered = true;
    REQUIRE(answered == true);
}

/*

    Cube Sort

*/

TEST_CASE("Cube Sort Can Sort Array"){
    std::vector<int> arrSorted;
    int amount = 10;
    for(int i = 1; i <= amount; i++){
        arrSorted.push_back(i);
    }
    std::vector<int> arr = arrSorted;
    for(int i = arr.size() - 1; i >= 0; i--){
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        //std::cout<<"unsorted at ~"<<(i + 1)<<"~ : "<<arr[i]<<std::endl;
    }
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    CubeSort<int> cube;
    arr = cube.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Cube Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}
TEST_CASE("Cube Sort Can Handle 1 Item"){
    std::vector<int> arrSorted = {1};
    std::vector<int> arr = arrSorted;
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    CubeSort<int> cube;
    arr = cube.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Cube Sort Can Handle Empty Array"){
    std::vector<int> arr = {};
    std::vector<int> arrSorted = {};
    CubeSort<int> cube;
    bool arraySorted = true;
    arr = cube.Sort(arr);
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Cube Sort Can Sort Arrays of the same value"){
    std::vector<int> arrSorted;
    int amount = 30;
    for(int i = 1; i <= amount; i++){
        arrSorted.push_back(1);
    }
    std::vector<int> arr = arrSorted;
    for(int i = arr.size() - 1; i >= 0; i--){
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        //std::cout<<"unsorted at ~"<<(i + 1)<<"~ : "<<arr[i]<<std::endl;
    }
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    CubeSort<int> cube;
    arr = cube.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Cube Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Cube Sort Can Sort negitive Arrays"){
    std::vector<int> arrSorted;
    int amount = 30;
    for(int i = 1; i <= amount; i++){
        arrSorted.push_back(i - 100);
    }
    std::vector<int> arr = arrSorted;
    for(int i = arr.size() - 1; i >= 0; i--){
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        //std::cout<<"unsorted at ~"<<(i + 1)<<"~ : "<<arr[i]<<std::endl;
    }
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    CubeSort<int> cube;
    arr = cube.Sort(arr);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Cube Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

/*

    Binary Search

*/
// TEST_CASE("Binary Search Works with a top half num"){
//     int amount = 30;
//     int n;
//     std::vector<int*> arr(n, nullptr);
//     for(int i = 0; i < amount; i++){
//        *arr[i] = i + 1;
//     }
//     int target = 26;
//     BinarySearch search;
//     int returned = search.Search(arr, 0, target, amount);
//     std::cout<<"looking for : "<<target<<std::endl<<"found : "<<returned<<std::endl;
//     REQUIRE(returned == target);

// }