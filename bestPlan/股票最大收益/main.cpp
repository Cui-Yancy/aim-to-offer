#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(!prices.size()) return 0;
        int min = prices[0];    //记录可以买入的最小值
        int max = prices[0];    //记录可以卖出的最大值
        int profit = 0;         //记录最大收益

        for(int i=0; i<prices.size(); i++)
        {
            //当前价格低于最低买入价格时，买入，卖出的起始价格也是当前价格
            if(prices[i] < min) {min = prices[i]; max = prices[i];}
            //当前价格大于最大卖出价格时，卖出
            if(prices[i] > max)
            {
                max = prices[i];
                //如果收益比最大收益还大，更新收益
                if((max - min)>profit) profit = max -min;
            }
        }

        return profit;
    }
};