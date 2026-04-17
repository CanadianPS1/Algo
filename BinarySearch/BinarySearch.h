#include <iostream>
#include <vector>
class BinarySearch{
    public:
    //has to be sorted
    //if null return -1

    /*
        check if the array is empty
            check if our start is out of the bounds of the array
                if it is we return -1
            check if we found the target value
                if we did then we return the target value
            check if the target value is on the right side
                if it is then we return a recersive call sending our range to the right
            if it isnt then we return a recersive call sending our range to the left
    
        Time = O(log n)
        Size O(1)
    */
    static int Search(std::vector<int> arr, int target, int start, int end){
        if(arr.size() > 0){
            if(start > end) return -1;
            int mid = start + (end - start) / 2;
            if(arr[mid] == target) return mid;
            else if(arr[mid] < target) return Search(arr, target, mid + 1, end);
            else return Search(arr, target, start, mid - 1);
        }else return -1;
    }
};