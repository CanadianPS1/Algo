#include <vector>
#include <iostream>
#include <unordered_map>
#include <stdio.h>
using namespace std;
//https://leetcode.com/problems/two-sum/description/
class TwoSum{
    public:
    /*
        loop through each insence of each instence of the vector
        check if their the same number, if they are then skip it
        check if i + j = the target if it does return it as a vector
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(nums[i] + nums[j] == target && i != j) return {i,j};
            }
        }
        return {0,0};
    }
};
//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/1967168810/
class AddTwoNumbers{
    public:
    /*
        get the length of the needle
        loop through the length of the haystack - the length of the needle
        look at each index + length at a time and see if its the needle
        if it is return the index and if it doesnt exist return -1
    */
    int strStr(string haystack, string needle){
        return haystack.find(needle);
    }
};
// class CodeWar{
    
//     public:
//     static std::string orderWeight(const std::string &strng){
//         std::unordered_map<int, std::string> temp;
//         std::string tempString = strng;
//         char charArr[strng.length() + 1];
//         //strcpy(charArr, strng.c_str());
//         int place = 0, minWeight = 0, maxWeight = 0;
//         for(int i = 0; i < charArr.Length(); i++){
//             char space = ' ';
//             if(charArr[i] == space){
//                 int weight = 0;
//                 std::string value = "";
//                 for(int j = place; j < i - 1; j++){
//                     weight += charArr[i] - '0';
//                     value += charArr[i];
//                     place++;
//                     if(weight < minWeight) minWeight = weight;
//                     if(weight > maxWeight) maxWeight = weight;
//                 }
//                 temp.insert({weight, value});
//             }else continue;
//         }
//         std::string finalStd = "";
//         for(int i = minWeight; i < maxWeight; i++){
//             if(temp.find(i) != temp.end()){
//                 finalStd += temp.at(i);
//             }
//         }
//         return finalStd;
//     }

// };
