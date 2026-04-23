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
    std::vector<T> Sort(std::vector<T> arr, int start, int end){
        MergeSorting(arr, start, end);
        return arr;
        
    }
    void MergeSorting(std::vector<T> &arr, int start, int end){
        if(arr.size() > 0){
            if(start > end) return;
            int middle = (start - end) / 2;
            MergeSorting(arr, start, middle);
            MergeSorting(arr, middle + 1, end);
            Merge(arr, start, middle, end);
        }else return;
    }
    void Merge(std::vector<T> &arr, int start, int middle, int end){
        std::cout<<"merging"<<std::endl;
    }
};