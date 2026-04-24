#include <iostream>
#include <vector>
/*
    First we want to split the array into a bunch of smaller arrays
        we can do this by recersivly calling our method and spliting the scope each time, simuler to a binary search
    Then we Merge
        we merge by creating 2 arrays left and right
            then we fill them with their corisponding values
        then we iterate through the arrays until we get to the end of them, merging in elements and incromenting 
        when their smaller then the corisponding element

        then we figure out which array we didnt finish iterating through and finish it off by merging the rest of the values

         Time O(n log n)
        Space O(n)
*/
template <typename T>
class MergeSort{
    public:
    std::vector<T> Sort(std::vector<T> arr, int start, int end){
        MergeSorting(arr, start, end);
        return arr;
        
    }
    void MergeSorting(std::vector<T> &arr, int start, int end){
        if(arr.size() > 1){
            if(start >= end) return;
            int middle = start + (end - start) / 2;
            MergeSorting(arr, start, middle);
            MergeSorting(arr, middle + 1, end);
            Merge(arr, start, middle, end);
        }else return;
    }
    void Merge(std::vector<T> &arr, int start, int middle, int end){
        int leftIncromenter, rightIncromenter, i, leftSize = middle - start + 1, rightSize = end - middle;
        //creates the arrays and fills them with the values on each side
        std::vector<T> leftArr(leftSize), rightArr(rightSize);
        for(leftIncromenter = 0; leftIncromenter < leftSize; leftIncromenter++) leftArr[leftIncromenter] = arr[start + leftIncromenter];
        for(rightIncromenter = 0; rightIncromenter < rightSize; rightIncromenter++) rightArr[rightIncromenter] = arr[middle + 1 + rightIncromenter];
        leftIncromenter = 0;
        rightIncromenter = 0;
        i = start;
        //main merge, does until 1 array is gone through
        while(leftIncromenter < leftSize && rightIncromenter < rightSize){
            if(leftArr[leftIncromenter] <= rightArr[rightIncromenter]){
                arr[i] = leftArr[leftIncromenter];
                leftIncromenter++;
            }else{
                arr[i] = rightArr[rightIncromenter];
                rightIncromenter++;
            }
            i++;
        }
        //handles the left overs from the first merge with the left array
        while(leftIncromenter < leftSize){
            arr[i] = leftArr[leftIncromenter];
            leftIncromenter++;
            i++;
        }
        //handles the left overs from the first merge with the right array
        while(rightIncromenter < rightSize){
            arr[i] = rightArr[rightIncromenter];
            rightIncromenter++;
            i++;
        }
    }
};