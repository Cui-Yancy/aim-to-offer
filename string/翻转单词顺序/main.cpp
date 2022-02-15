#include <iostream>
using namespace std;
#include <string>

//将字符串中的单词逆序输出
//考虑从原字符串尾部开始扫描
//先扫描到第一个非空格字符，表示第一个单词的结束位置
//再从该位置-1的开始扫描，寻找第一个空格位置，即第一个单词的起始位置
//将这两个位置之间的子字符串插入进临时字符串的尾部即可
//循环查找单词，向尾部插入即可

class Solution {
public:
    string reverseWords(string s) {
        // int pos = s.find(' ');
        // int start = -1;
        // string ret = "";
        // while(pos!=-1)
        // {
        //     if(pos>(start+1))
        //     {
        //         ret.insert(0,s.substr(start+1,(pos-start-1)));
        //         ret.insert(ret.begin(),' ');
        //     }
        //     start = pos;
        //     pos = s.find(' ',start+1);
        // }
        // if(start == -1) ret+=s;         //如果起始位置还是-1，说明语句中不存在空格
        // else if(start<=(s.length()-2))       //如果最后一个单词后边没有空格，就会略过
        //     ret.insert(0,s.substr(start+1,(s.length()-start-1)));
        // if(ret[0]==' ') ret.erase(0,1); //如果最后一个单词后边有空格，就会多产生空格
        // return ret;

        if(!s.length()) return {};
        string ret = "";
        int cPos = s.length()-1;    //第一个非空格下标
        int sPos = cPos;            //第一个空格下标
        while(cPos>=0)
        {
            while(cPos>=0 && s[cPos]==' ') cPos--;
            if(cPos<0) break;       //如果查找字符位置到了-1，就结束搜索
            sPos = cPos-1;          //从非空格字符的前一个位置开始查找
            while(sPos>=0 && s[sPos]!=' ') sPos--;
            ret.insert(ret.length(),s.substr(sPos+1,cPos-sPos));
            ret.insert(ret.end(), ' '); //在最后一个位置，必定多输出一个空格
            cPos=sPos-1;
        }
        if(!ret.empty()) ret.erase(ret.length()-1,1);    //字符串非空，则需要删除最后一个空格
        return ret;

    }
};