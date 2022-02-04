#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        //return s.substr(n,s.length()-n)+s.substr(0,n);
        string str = "";
        for(int i=n; i<n+s.length(); i++)
        {
            str += s[i%s.length()];
        }
        return str;
    }
};