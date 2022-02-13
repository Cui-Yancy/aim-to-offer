
class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, num;
        for(int i=0;i<n;i++)
        {
            num = b;
            b = (a+b)%1000000007;
            a = num;
        }
        return a;
    }
};