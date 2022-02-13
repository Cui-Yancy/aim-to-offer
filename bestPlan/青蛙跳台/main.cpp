//青蛙一次可以跳一个台阶或者两个台阶
//0阶--1种可能
//1阶--1种可能
//2     2
//3     3
//4     5
//5     8
//6     13

class Solution {
public:
    int numWays(int n) {
        int a = 1, b = 1, num;
        for(int i=0; i<n; i++)
        {
            num = b;
            b = (a+b)%1000000007;
            a = num;
        }
        return a;
    }
};