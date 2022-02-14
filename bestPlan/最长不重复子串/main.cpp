#include <iostream>
using namespace std;
#include <string>

//假设Sc字符串，S中以S[i-1]结尾的最长的不重复子串长度为dp[i-1]
//dp[i] = dp[i-1]+1     最近的c在S中dp[i-1]长度之外，或者c不存在
//      = j - i         j为当前位置，i为最近一个相同位置

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.length()) return 0;
        int a[255];                             //记录最近的字符位置
        for(int i=0;i<255;i++) a[i] = -1;
        int ret = 0;                            //记录最大的包含右字符不重复长度
        int len = 0;                            //记录dp[i-1]
        for(int i=0; i<s.length(); i++)
        {
            int pos = a[s[i]];                  //查询最近的s[i]字符的位置
            if(pos==-1 || pos<(i-len)) len++;   //如果字符不存在或者在长度之外 +1
            else len = i-pos;                   //在长度之内， len = i-pos
            ret = len>ret?len:ret;              //始终记录最大值
            a[s[i]] = i;                        //更新最新的s[i]字符所在位置
        }
        return ret;
    }
};