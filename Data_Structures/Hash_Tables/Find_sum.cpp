#include <iostream>
#include <vector>
using namespace std;

twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(hash.containsKey(target - nums[i]))
                return new int[] {i, hash.get(target - nums[i])};
            
            hash.put(nums[i], i);
        }
        
        return new int[2];        
    }

int main(){
    int vector<int> nums = [2,7,1,15];
    int target = 9;

    cout<< "twoSum()";

    return 0;
}