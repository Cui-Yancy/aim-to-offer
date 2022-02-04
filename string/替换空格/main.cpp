#include <iostream>
using namespace std;
#include <string>

//string库函数用法
/*  find:
        find(char a):   从首部查找，返回第一个相同字符下标位置，找不到时返回-1
        find(string s): 从首部开始，返回相同字符串起始下标，否则返回-1
常用    find(char a, int pos):  从pos下标位置开始查找，返回第一个相同位置下标，否则返回-1
    length:             返回实际字符串长度，不算结尾/0
    erase:
        erase(int pos): 从pos开始全部删除
常用    erase(int pos,int len): 从pos开始，删除len长度的字符
        erase(::iterator it1, it2): 从迭代器位置it1开始，删除至it2，不包含it2
    insert:
        insert(int pos,string s):   在下标位置pos处，插入字符串，必须是字符串，不能是字符
*/

class Solution {
public:
    string replaceSpace(string s) {
        string str = s;
        int pos = str.find(' ');
        int start = 0;
        while(pos!=-1)
        {
            str.erase(pos,1);
            str.insert(pos,"%20");
            start = pos+3;
            pos = str.find(' ',start);
        }
        return str;
    }
};