#include "../External/catch_amalgamated.hpp"
#include <iostream>
#include <vector>
//#include <chrono>
#include <algorithm>
#include <random>
#include <cstdint>
#include "../Testing/Test.h"
#include "../BubbleSort/BubbleSort.h"
#include "../SelectionSort/SelectionSort.h"
#include "../InsertionSort/InsertionSort.h"
#include "../CubeSort/CubeSort.h"
#include "../MergeSort/MergeSort.h"
#include "../QuickSort/QuickSort.h"
#include "../LeetCode/LeetCode1.c++"
#include "../BinarySearch/BinarySearch.h"
#include "../Isomorphic/Isomorphic.h"
#include "../NQueens/NQueens.h"
#include <bits/stdc++.h>
int amount = 100;
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
    std::cout<<"   Bubble Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
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
    std::cout<<"Selection Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
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
    std::cout<<"Insertion Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
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
    std::cout<<"     Cube Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
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
//these tests were not written by ai so dw i didnt plagerise
// TEST_CASE("Binary Search Works with a top half num"){
    
//     int n;
//     std::vector<int> arr;
//     for(int i = 0; i < amount; i++){
//        arr.push_back(i + 1);
//     }
//     int target = 20;
//     BinarySearch search;
//     int returned = search.Search(arr, target, 0, amount - 1);
//     std::cout<<"looking for : "<<target<<std::endl<<"found : "<<returned<<std::endl;
//     REQUIRE(arr[returned] == target);
// }
// TEST_CASE("Binary Search Works with a bottom half num"){
    
//     int n;
//     std::vector<int> arr;
//     for(int i = 0; i < amount; i++){
//        arr.push_back(i + 1);
//     }
//     int target = 10;
//     BinarySearch search;
//     int returned = search.Search(arr, target, 0, amount - 1);
//     std::cout<<"looking for : "<<target<<std::endl<<"found : "<<returned<<std::endl;
//     REQUIRE(arr[returned] == target);
// }
// TEST_CASE("Binary Search Works with 1 item in the list"){
//     int amount = 1;
//     int n;
//     std::vector<int> arr;
//     for(int i = 0; i < amount; i++){
//        arr.push_back(i + 1);
//     }
//     int target = 1;
//     BinarySearch search;
//     int returned = search.Search(arr, target, 0, amount - 1);
//     std::cout<<"looking for : "<<target<<std::endl<<"found : "<<returned<<std::endl;
//     REQUIRE(arr[returned] == target);
// }
// TEST_CASE("Binary Search handleds empty array"){
//     int amount = 0;
//     int n;
//     std::vector<int> arr;
//     for(int i = 0; i < amount; i++){
//        arr.push_back(i + 1);
//     }
//     int target = -1;
//     BinarySearch search;
//     int returned = search.Search(arr, target, 0, amount - 1);
//     std::cout<<"looking for : "<<target<<std::endl<<"found : "<<returned<<std::endl;
//     REQUIRE(returned == target);
// }

/*

    Isomorphis

*/

// i didnt see where it said the amount of tests we needed was so i just have 1 for each checking it it correctly did it
TEST_CASE("Can find the loose isomorphic patern of a single word"){
    std::string testWord = "warrior";
    std::string correctPatern = "1 1 1 1 3";
    Isomorphic isomorph;
    std::string result = isomorph.GetLoosePattern(testWord);
    //std::cout<<"looking for : "<<correctPatern<<"\nReseved : "<<result<<std::endl;
    REQUIRE(correctPatern.compare(result) == 0);
}

TEST_CASE("Can find the exact isomorphic patern of a single word"){
    std::string testWord = "warrior";
    std::string correctPatern = "0 1 2 2 3 4 2";
    Isomorphic isomorph;
    std::string result = isomorph.GetExactPattern(testWord);
    //std::cout<<"looking for : "<<correctPatern<<"\nReseved : "<<result<<std::endl;
    REQUIRE(correctPatern.compare(result) == 0);
}

TEST_CASE("Can find the loose isomorphic patern of a array of words"){
    std::vector<string> testWords = {"ate", "bar", "eat", "fit", "sap", "look", "meet", "seep", "seer", "took", "add", "egg", "foo", "gag", "tot", "yay"};
    std::unordered_map<std::string, std::string> correctPaterns = 
    {
        {"1 1 1", "ate bar eat fit sap"},
        {"1 2 1", "look meet seep seer took"},
        {"1 2", "add egg foo gag tot yay"},
    };
    Isomorphic isomorph;
    std::unordered_map<std::string, std::string> result = isomorph.FindLooseIsomorphs(testWords);
    // for(const auto& [key, value] : result){
    //     std::cout<<key << " : "<< value<<std::endl;
    // }
    REQUIRE(result == correctPaterns);
}


TEST_CASE("Can find the exact isomorphic patern of a array of words"){
    std::vector<string> testWords = {"ate", "bar", "eat", "fit", "sap", "look", "meet", "seep", "seer", "took", "add", "egg", "foo", "gag", "tot", "yay"};
    std::unordered_map<std::string, std::string> correctPaterns = 
    {
        {"0 1 0", "gag tot yay"},
        {"0 1 1", "add egg foo"},
        {"0 1 1 2", "look meet seep seer took"},
        {"0 1 2", "ate bar eat fit sap"},
    };
    Isomorphic isomorph;
    std::unordered_map<std::string, std::string> result = isomorph.FindExactIsomorphs(testWords);
    // for(const auto& [key, value] : result){
    //     std::cout<<key << " : "<< value<<std::endl;
    // }
    REQUIRE(result == correctPaterns);
}

/*

    Merge Sort

*/

TEST_CASE("Merge Sort Can Sort Array"){
    std::vector<int> arrSorted;
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
    MergeSort<int> merge;
    arr = merge.Sort(arr, 0, amount - 1);
    auto eTime = std::chrono::high_resolution_clock::now();
    std::cout<<"    Merge Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}
TEST_CASE("Merge Sort Can Handle 1 Item"){
    std::vector<int> arrSorted = {1};
    std::vector<int> arr = arrSorted;
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    MergeSort<int> merge;
    arr = merge.Sort(arr, 0, amount - 1);
    auto eTime = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Merge Sort Can Handle Empty Array"){
    std::vector<int> arr = {};
    std::vector<int> arrSorted = {};
    MergeSort<int> merge;
    bool arraySorted = true;
    arr = merge.Sort(arr, 0, amount - 1);
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Merge Sort Can Sort Arrays of the same value"){
    std::vector<int> arrSorted;
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
    MergeSort<int> merge;
    arr = merge.Sort(arr, 0, amount - 1);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Merge Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Merge Sort Can Sort negitive Arrays"){
    std::vector<int> arrSorted;
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
    MergeSort<int> merge;
    arr = merge.Sort(arr, 0, amount - 1);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Merge Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

/*

    Quick Sort

*/

TEST_CASE("Quick Sort Can Sort Array"){
    std::vector<int> arrSorted;
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
    QuickSort<int> quick;
    arr = quick.Sort(arr, 0, amount - 1);
    auto eTime = std::chrono::high_resolution_clock::now();
    std::cout<<"    Quick Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}
TEST_CASE("Quick Sort Can Handle 1 Item"){
    std::vector<int> arrSorted = {1};
    std::vector<int> arr = arrSorted;
    bool arraySorted = true;
    auto sTime = std::chrono::high_resolution_clock::now();
    QuickSort<int> quick;
    arr = quick.Sort(arr, 0, amount - 1);
    auto eTime = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Quick Sort Can Handle Empty Array"){
    std::vector<int> arr = {};
    std::vector<int> arrSorted = {};
    QuickSort<int> quick;
    bool arraySorted = true;
    arr = quick.Sort(arr, 0, amount - 1);
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Quick Sort Can Sort Arrays of the same value"){
    std::vector<int> arrSorted;
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
    QuickSort<int> quick;
    arr = quick.Sort(arr, 0, amount - 1);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Quick Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

TEST_CASE("Quick Sort Can Sort negitive Arrays"){
    std::vector<int> arrSorted;
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
    QuickSort<int> quick;
    arr = quick.Sort(arr, 0, amount - 1);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"Quick Sort: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(eTime - sTime).count()<<" nanoseconds"<<std::endl;
    for(int i = 0; i < arr.size(); i++){
        //std::cout<<arr[i]<<std::endl;
        if(arr[i] != arrSorted[i]) arraySorted = false;
    }
    REQUIRE(arraySorted == true);
}

/*

    N Queens

*/

TEST_CASE("N Queens finds the correct amount of solutions for 4 queens"){
    int amountOfQueens = 4;
    NQueens nqueen;
    std::vector<uint8_t> solutions = {0,0,0,0};
    auto sTime = std::chrono::high_resolution_clock::now();
    nqueen.FindQueen(amountOfQueens, 0, solutions);
    auto eTime = std::chrono::high_resolution_clock::now();
    std::cout<<"    N Queens 4: "<<std::chrono::duration_cast<std::chrono::seconds>(eTime - sTime).count()<<" seconds"<<std::endl;
    //std::cout<<"amount of queens found: "<<nqueen.GetAmountOfSolutions()<<"\n expected : 4"<<std::endl;
    REQUIRE(nqueen.GetAmountOfSolutions() == 2);
}

TEST_CASE("N Queens finds the correct first solution for 4 queens"){
    int amountOfQueens = 4;
    NQueens nqueen;
    std::vector<uint8_t> solutions = {1, 3, 0, 2};
    auto sTime = std::chrono::high_resolution_clock::now();
    nqueen.FindQueen(amountOfQueens, 0, solutions);
    auto eTime = std::chrono::high_resolution_clock::now();
    //std::cout<<"N Queens 4: "<<std::chrono::duration_cast<std::chrono::seconds>(eTime - sTime).count()<<" seconds"<<std::endl;
    std::vector<uint8_t> answer = nqueen.GetFirstSolution();
    //for(int i = 0; i < answer.size(); i++) std::cout<<answer[i]<<std::endl;
    REQUIRE(answer == solutions);
}

TEST_CASE("N Queens finds the correct amount of solutions for N queens"){
    int amountOfQueens = 17;
    NQueens nqueen;
    std::vector<uint8_t> solutions;
    for(int i = 0; i < amountOfQueens; i++) solutions.push_back(0);
    auto sTime = std::chrono::high_resolution_clock::now();
    nqueen.FindQueen(amountOfQueens, 0, solutions);
    auto eTime = std::chrono::high_resolution_clock::now();
    std::cout<<"    N Queens "<<amountOfQueens<<" : "<<std::chrono::duration_cast<std::chrono::seconds>(eTime - sTime).count()<<" seconds"<<std::endl;
    //std::cout<<"amount of queens found: "<<nqueen.GetAmountOfSolutions()<<"\n expected : 4"<<std::endl;
    REQUIRE(nqueen.GetAmountOfSolutions() == 14772512);
}
