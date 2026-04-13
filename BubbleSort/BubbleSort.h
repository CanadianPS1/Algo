#include <iostream>
#include <vector>
/*
For Loop
    For Loop
        check if the place is bigger then the next
            swap
        else 
            skip
OC = O(n ^2)
SC = O(1)
*/
template <typename T>
class BubbleSort{
    public:
    std::vector<T> Sort(std::vector<T> arr){
        int size = arr.size();
        if(!arr.empty()){
            for(int i = 0; i <= size; i++){
                bool swapped = false;
                for(int j = 0; j <= size; j++){
                    if(j < size - 1 && j < (size - i)){
                        if(arr[j] > arr[j + 1]){
                            swapped = true;
                            T temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                if(!swapped) break;
            }
        }
        return arr;
    }
};