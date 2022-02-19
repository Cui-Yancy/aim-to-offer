#include <iostream>
using namespace std;
#include <vector>

//从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子,即这5张牌是不是连续的。
//2～10为数字本身，A为1，J为11，Q为12，K为13
//而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

//考虑使用哈希表，记录每张牌的出现次数，以及除了0的最小值和最大值
//从最小值开始，到最大值，如果缺牌，用0代替
//如果出现两张以上相同的牌，返回假
//最后看大小王的数量，如果小于0说明缺牌太多返回假，否则返回真

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        char a[14] = {0,};
        int max = 0, min = 14;
        for(int i=0;i<5;i++)
        {
            a[nums[i]]++;
            if(nums[i]<min && min) min = nums[i];
            if(nums[i]>max) max = nums[i];
        }
        for(int i=min;i<=max;i++)
        {
            if(a[i]==0) a[0]--;
            if(a[i]>1) return false;
        }
        if(a[0]<0) return false;
        return true;
    }
};