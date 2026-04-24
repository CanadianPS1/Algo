#include <iostream>
#include <vector>
/*
    main
        if the array has a valid amount of items then 
            call quick sort with the array and the start and end of the array
        return the array


    quick sort (takes in a vector pointer, the start, the end)
        if it has an invalid start and end (out of bounds) return and end recurtion
        set a pivot to the last item in the array
        set your left and right, the right to start and the left to 1 less then start
        loop for aslong as the right isnt at the end
            if the arr[right] is less than the pivot
                incroment left
                swap the values of r and l
                incroment right
            else incroment the right
            swap the pivot and left + 1 to put the pivot in its sorted spot
            recerse through with the start going to the left
            recerse through with l + 2 and the end (going to the right)
        
         Time O(n log n)
        Space O(1)
*/
template <typename T>
class QuickSort{
    public:
    std::vector<T> Sort(std::vector<T> arr, int start, int end){
        if(arr.size() > 1) QuickSorting(arr, start, end);
        return arr;
    }
    void QuickSorting(std::vector<T> &arr, int start, int end){
        if(start >= end) return;
        int pivot = arr[end];
        int l = start - 1, r = start;
        for(; r < end;){
            if(arr[r] < pivot){
                l++;
                int temp;
                temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
                r++;
            }else r++;
        }
        int temp = arr[l + 1];
        arr[l + 1] = pivot;
        arr[end] = temp;
        QuickSorting(arr, start, l);
        QuickSorting(arr, l + 2, end);
    }
};