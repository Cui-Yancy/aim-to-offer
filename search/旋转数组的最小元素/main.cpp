#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0, high = numbers.size()-1;
        int mid;
        while(low<high)
        {
            mid = (low+high)/2;
            //中间元素大于右端元素
            if(numbers[mid]>numbers[high]) low = mid+1;
            
            //中间元素小于右端元素
            else if(numbers[mid]<numbers[high]) high = mid;
            else high--;
        }
        return numbers[low];
    }
};