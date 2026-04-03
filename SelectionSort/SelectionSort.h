#include <iostream>
#include <vector>
/*
Loop through each value vs each value
check if the j value is lower then the lowest found j value
check if the smallest value is less then the i value
if it is swap them
OC = O(n^2)
SC = O(1)
*/
template <typename T>
class SelectionSort{
    public:
    std::vector<T> Sort(std::vector<T> arr){
        int size = arr.size();
        if(size > 0){
            int lowestNumber = arr[0];
            for(int i = 0; i < size; i++){
                lowestNumber = i;
                for(int j = (i + 1); j < size; j++){
                    if(arr[j] < arr[lowestNumber]) lowestNumber = j;
                }
                if(arr[lowestNumber] < arr[i]){
                    int temp = arr[i];
                    arr[i] = arr[lowestNumber];
                    arr[lowestNumber] = temp;
                }
            }
        }
        return arr;
    }
};