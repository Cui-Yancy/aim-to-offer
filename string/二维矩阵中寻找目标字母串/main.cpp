#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>

//在使用for循环时，循环变量最好在for内申明，否则多重for循环可能循环变量初值只能设置一次
//在设计函数时，最好使用引用传递，防止过多值传递，增加内存开销
//这道题使用值传递时，执行时间和内存消耗远高于引用传递，主要是由于构建新的字符串

class Solution {
public:
    int xL,yL,wordL;
    bool exist(vector<vector<char>>& board, string word) {
        xL = board.size();
        yL = board[0].size();
        wordL = word.length();
        for(int x=0; x<xL; x++)
            for(int y=0; y<yL; y++)
                if(isExit(board,word,x,y,0)) return true;
        return false;
    }

    bool isExit(vector<vector<char>>& board, string word, int x, int y, int k)
    {
        if(k>=wordL) return true;
        if(x>=xL || y>=yL || x<0 || y<0 || board[x][y]!=word[k]) return false;
        bool ret = false;
        board[x][y] = '\0';
        ret = isExit(board,word,x-1,y,k+1) || isExit(board,word,x+1,y,k+1) ||
                isExit(board,word,x,y-1,k+1) || isExit(board,word,x,y+1,k+1);
        board[x][y] = word[k];
        return ret;
    }
};

