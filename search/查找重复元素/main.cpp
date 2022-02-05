#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // unordered_map<int,int> map;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(map[nums[i]]!=1)
        //     {
        //         map[nums[i]]=1;
        //     }
        //     else
        //     {
        //         return nums[i];
        //     }
        // }
        // return -1;

        int i=0;
        while(i<nums.size())
        {
            if(nums[i]==i)
            {
                i++;
                continue;
            }
            if(nums[nums[i]]==nums[i]) return nums[i];
            else swap(nums[nums[i]],nums[i]);
        }
        return -1;
    }
};