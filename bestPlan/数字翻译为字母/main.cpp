#include <iostream>
using namespace std;

//从高位到低位
//dp[i] =   dp[i-1] num[i-1] > 2, =0, =2 num[i]>5
//          dp[i-1]+1 num[i-1]

//从低位到高位
//如果a(bX)中，ab可以翻译为字母，那么可以是(ab)X或者a(bX) 
//dp[i] = dp[i-1] + dp[i-2] num[i]>2, =0, num[i]=2 num[i-1]>5

class Solution {
public:
    int translateNum(int num) {
        int sum = 1;                //用于记录dp[i-1]
        int sum2 = 1;               //dp[i-2]
        int xOld = num%10;          //用于记录num[i-1]
        num/=10;
        while(num)
        {
            int xNew = num % 10;    //用于记录num[i]
            int tmp = sum;
            if(xNew==1 || (xNew==2 && xOld<6)) sum+=sum2;
            sum2 = tmp;
            num /= 10;
            xOld = xNew;
        }
        return sum;
    }
};