#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
/*
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
template <typename T>
class CubeSort{
    public:
    std::vector<T> Sort(std::vector<T> arr){
        int size = arr.size();
        std::unordered_map<int, int> map;
        int minValue = 0;
        int maxValue = 0;
        for(int i = 0; i < size; i++){
            map.insert({arr[i], arr[i]});
            if(arr[i] < minValue) minValue = arr[i];
            if(arr[i] > maxValue) maxValue = arr[i];
        }
        arr.clear();
        for(int i = minValue; i <= maxValue; i++){
            if(map.find(i) != map.end()) arr.push_back(i);
        }
        return arr;
    }
};