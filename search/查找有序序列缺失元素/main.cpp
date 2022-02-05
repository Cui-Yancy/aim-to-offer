#include <iostream>
using namespace std;
#include <vector>

//有序序列均考虑采用二分法
//以nums[mid]==mid为条件进行区分
//右侧是缺失元素所在位置

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int i;
        // for(i=0; i<nums.size() && nums[i]==i; i++);
        // return i;
        int low = 0,high = nums.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==mid) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};