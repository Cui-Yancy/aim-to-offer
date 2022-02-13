#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];  //第i个元素之前的 包含第i-1个元素的子序列和的最大值
        int ret = sum;      //记录最大的子序列和
        for(int i=1; i<nums.size(); i++)
        {
            if(sum<=0) sum = nums[i];   //如果之前的子序列最大值为非正数，就不需要再加上之前的
            else sum += nums[i];        //否则就将最大值加上
            ret = ret>sum?ret:sum;      //新的最大值和旧的最大值取最大的记录下来
        }
        return ret;
    }
};