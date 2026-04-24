#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
template <typename T>
class InsertionSort{
    public:
    std::vector<T> Sort(std::vector<T> arr){
        int size = arr.size();
        /*
            check for if the data scructure has elements
                declare a temp var on the heap and a incrementing int on the stack
                loop through each element in the array
                    set the temp to the arr[i] of the current iteration
                    set the incrementing var to 1 less then the i
                    loop while your iterator isnt less then zero, and the temp is less than the iterator
                    if we use a while loop we can cut out a if statment from the code
                        set the arr at the increment + 1 to the arr at the increment
                        lower the iterator, this way its going through the datascructure (vector) in reverse
                    set the arr at the increment + 1 to the temp, becuase once the array stops we found that either its
                    greater than nothing or it belongs infront of the increment
                now we can delete the temp from memory
            return the array, if it had no elements then nothing changed, thats why we return it outside the loops
        OC = O(n^2)
        SC = O(1)
        */
        if(size > 0){
            int* temp = new int;
            int count;
            for(int i = 0; i < size; i++){
                *temp = arr[i];
                count = i - 1;
                while(0 <= count && *temp < arr[count]){
                    arr[count + 1] = arr[count];
                    count--;
                }
                arr[count + 1] = *temp;
            }
            delete temp;
        }
        return arr;
    }
};