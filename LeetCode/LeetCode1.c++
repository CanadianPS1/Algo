#include <vector>
#include <iostream>
using namespace std;
//to sum
class TwoSum {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                cout<<nums[i]<<" + "<<nums[j]<<" = "<<nums[i] + nums[j]<<endl;
                if(nums[i] + nums[j] == target && i != j) return {i,j};
            }
        }
        return {0,0};
    }
};