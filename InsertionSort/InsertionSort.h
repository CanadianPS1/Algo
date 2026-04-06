#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
/*

OC = O(n^2)
SC = O(1)
*/
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
        if(size > 0){
            //arr.clear();
            int temp = arr[1];
            arr.erase(find(arr.begin(), arr.end(), 1));
            arr.insert((arr.begin() + 1), temp);
            // for(int i = 0; i < size; i++){
            //     //std::cout<<"i = "<<i<<std::endl;
            //     for(int j = 0; j < i; j++){
            //        // std::cout<<"  j = "<<j<<" = "<<arr[j]<<std::endl;
            //         if(arr[i] < arr[j]){
            //             arr.erase(find(arr.begin(), arr.end(), i));
            //             arr.insert(arr.begin() + j - 1, arr[i]);
            //             std::cout<<"put "<<arr[i]<<" before "<<arr[j]<<std::endl;
            //             //std::cout<<"i: "<<arr[i]<<" < "<<" j:"<<arr[j]<<std::endl;
            //             break;
            //         }else{
            //             int temp = arr[i];
            //             arr.erase(find(arr.begin(), arr.end(), i));
            //             arr.insert(arr.begin() + j, temp);
            //             std::cout<<"put "<<arr[i]<<" after "<<arr[j]<<std::endl;
            //             break;
            //         }
            //     }
            // }
        }
        return arr;
    }
};