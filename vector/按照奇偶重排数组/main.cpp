#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(!nums.size()) return nums;
        int low = 0;
        int high = nums.size()-1;
        while(low<high)
        {
            while(nums[high]%2==0 && low<high) high--;
            while(nums[low]%2==1 && low<high) low++;
            int tmp = nums[high];
            nums[high] = nums[low];
            nums[low] = tmp;
            high--;
            low++;
        }
        return nums;
    }
};