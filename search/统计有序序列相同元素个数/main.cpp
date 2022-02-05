#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

//在非递减序列中，查找第一个大于目标值的元素下标
//如果为空容器则返回-1
//如果目标值很小，则返回0，目标值很大则返回容器大小
int searchBigger(vector<int>& nums, int target)
{
    if(nums.size()==0)
        return -1;
    int high = nums.size()-1,low = 0;
    int mid;
    while(low<=high)
    {
        mid = (high+low)/2;
        if(nums[mid] <= target) low = mid+1;    //mid等于目标值时，比目标大的元素还在右边
        else high = mid-1;
    }
    return low;
}

int search(vector<int>& nums, int target)
{
    return searchBigger(nums,target)-searchBigger(nums,target-1);
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0 || target<nums[0] || target>nums[nums.size()-1])
            return 0;
        int low = 0, high = nums.size()-1;
        int mid = (low+high)/2;
        int start = 0;
        while(low<=high)
        {
            if(nums[mid]==target && (mid==0 || nums[mid-1]<target))
            {
                start = mid;
                break;
            }
            if(nums[mid]<target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
            mid = (low+high)/2;
        }
        if(low>high) return 0;

        low = 0;
        high = nums.size()-1;
        mid = (low+high)/2;
        int end = 0;
        while(low<=high)
        {
            if(nums[mid]==target && (mid==nums.size()-1 || nums[mid+1]>target))
            {
                end = mid;
                break;
            }
            if(nums[mid]<=target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
            mid = (low+high)/2;
        }
        return end-start+1;
    }
};