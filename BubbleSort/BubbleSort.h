#include <iostream>
#include <vector>
template <typename T>
class BubbleSort{
    public:
    std::vector<T> Sort(std::vector<T> arr){
        int size = arr.size();
        if(!arr.empty()){
            for(int i = 0; i <= size; i++){
                for(int j = 0; j <= size; j++){
                    if(j < size - 1 && j < (size - i)){
                        if(arr[j] > arr[j + 1]){
                            T temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
            }
        }
        return arr;
    }
};