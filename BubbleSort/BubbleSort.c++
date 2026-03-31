#include <iostream>
#include "BubbleSort.h"
template <typename T>
void BubbleSort::Sort(T* arr[]){
    if(arr == nullptr){
        std::cout<<"Array Null";
    }
    for(int i = 0; i < arr.Length; i++){
        for(int j = 0; j < arr.Length; j++){
            if(arr[j] > arr[j + 1]){
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}