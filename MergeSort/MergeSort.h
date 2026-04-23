#include <iostream>
#include <vector>
/*
    check if the inner array is a size of 2
        if it isnt and has not been split it and recersivly call
        if it is then sort it and return
    if it already has been then merge the returned array in and sort it

*/
template <typename T>
class MergeSort{
    public:
    std::vector<T> Sort(std::vector<T> arr){
        if(arr.size() > 2){
            std::vector<T> left;
            std::vector<T> right;
            for(int i = 0; i < arr.size() / 2; i++) left.push_back(arr[i]);
            for(int i = (arr.size() - 1 / 2); (arr.size() - 1 / 2) < (arr.size() - 1); i++) right.push_back(arr[i]);
            



            std::cout<<"left array"<<std::endl;
            for(int i = 0; i < left.size(); i++){
                std::cout<<left[i]<<std::endl;
            }
            std::cout<<"right array"<<std::endl;
            for(int i = 0; i < right.size(); i++){
                std::cout<<right[i]<<std::endl;
            }
            right = Sort(right);
            left = Sort(left);
            return right;
        }else{
            // std::cout<<"new array"<<std::endl;
            // for(int i = 0; i < arr.size(); i++){
            //     std::cout<<arr[i]<<std::endl;
            // }
            return arr;
        }
    }
};