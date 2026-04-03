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
        int lowestNumber;
        int size = arr.size();
        for(int i = 0; i < size; i++){
            for(int j = 0; j < (size - i - 1); i++){
                if(arr[j + i + 1] < arr[lowestNumber]) lowestNumber = (j + i + 1);
            }
            if(arr[lowestNumber] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[lowestNumber];
                arr[lowestNumber] = temp;
            }
            std::cout<<arr[i]<<std::endl;
        }
        return arr;
    }
};