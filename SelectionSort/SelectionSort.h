#include <iostream>
#include <vector>
/*

OC = 
SC = 
*/
template <typename T>
class SelectionSort{
    public:
    std::vector<T> Sort(std::vector<T> arr){
        int *lowestNumber = new int;
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < (arr.size - i); i++){
                if(arr[j + i] < arr[lowestNumber]) lowestNumber = j;

            }
            
        }
    }
};