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
            i ripped this sort off the dome but it doesnt do the insertion
            but i really like what i came up with so ima keep it commented out
            but this sort is only good on large amounts of data

            pretty much with the power of the unorderd map if i know the smallest value and the largest value i can
            put everything into a unordered map with the key and the value equal to each spot of the arr (or what ever)
            then i can just loop through putting each number in the right sorted spot in the first iteration, but if i know
            the list of numbers doesnt have any gaps ie (1,2,3) and not (1,3,4) then i could just loop through it once without knowing the max value

            hashmap
            make each key the value
            for loop then grab each key and make the value at that spot of a returned array

            OC = O(n)
            SC = O(n)
        */

                    // std::unordered_map<int, int> evil;
                    // int minValue = 0;
                    // int maxValue = 0;
                    // for(int i = 0; i < size; i++){
                    //     evil.insert({arr[i], arr[i]});
                    //     if(arr[i] < minValue) minValue = arr[i];
                    //     if(arr[i] > maxValue) maxValue = arr[i];
                    //     //std::cout<<"unsorted : "<<arr[i]<<std::endl;
                    // }
                    // //std::cout<<"max: "<<maxValue<<"\nmin: "<<minValue<<std::endl;
                    // arr.clear();
                    // for(int i = minValue; i <= maxValue; i++){
                    //     //std::cout<<"i : "<<i<<std::endl;
                    //     if(evil.contains(i)){
                    //         arr.push_back(evil.at(i));
                    //         //std::cout<<evil.at(i)<<std::endl;
                    //     }
                    // }
                    // return arr;

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