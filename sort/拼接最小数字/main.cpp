#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stdlib.h>

//两个数字形成的字符串为 a b
//如果 a+b>b+a 说明应该将b放在a前边 a较大

class Solution {
public:
    string minNumber(vector<int>& nums) {
        string str = "";
        vector<string> v;
        for(int i=0;i<nums.size();i++)
            v.push_back(to_string(nums[i]));
        int n=v.size();
        //sort(v);
        quickSort(v,0,n-1);
        for(int i=0;i<n;i++)
            str+=v[i];
        return str;
        stoi(str);
    }

    void sort(vector<string> &v)
    {
        int len = v.size();
        for(int i=0;i<len-1;i++)
        {
            bool noExchange = true;
            for(int j=0;j<len-i-1;j++)
            {
                if((v[j]+v[j+1])>(v[j+1]+v[j])) {swap(v[j],v[j+1]);noExchange = false;}
            }
            if(noExchange) break;
        }
    }

    void quickSort(vector<string> &v, int low, int high)
    {
        if(low>=high) return;   //这里的判断条件必须是大于等于，如果本身就是递增序列
        int x=low, y=high;      //第一次快排之后low=high=0，子序列快排区间就会出现[0,-1]
        string mid = v[low];
        while(low<high)
        {
            while(low<high && (v[high]+mid)>=(mid+v[high])) high--;
            if(low==high) break;
            swap(v[low],v[high]);
            low++;
            while(low<high && (v[low]+mid)<=(mid+v[low])) low++;
            if(low==high) break;
            swap(v[low],v[high]);
            high--;
        }
        v[low] = mid;
        quickSort(v,x,low-1);
        quickSort(v,low+1,y);
    }
};