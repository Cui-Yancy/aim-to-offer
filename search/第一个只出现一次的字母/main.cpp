#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>

class Solution {
public:
    char firstUniqChar(string s) {
        if(s.length()==0)
            return ' ';
        unordered_map<char,int> map;
        for(int i=0;i<s.length();i++)
            map[s[i]]++;
        for(int i=0;i<s.length();i++)
        {
            if(map[s[i]]==1) return s[i];
        }
        return ' ';

    }
};