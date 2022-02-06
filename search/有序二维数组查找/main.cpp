#include <iostream>
using namespace std;
#include <vector>

//利用有序数组的性质，从右上(或左下)对角元素开始遍历
//如果目标值大于元素值，必定在下方位置，排除元素左侧一行，行++
//如果小于，必定在左侧位置，排除右侧一列，列--

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // if(matrix.size()==0 || matrix[0].size()==0)
        //     return false;
        // int xLow = 0, xHigh = matrix[0].size()-1;
        // int mid;
        // while(xLow<=xHigh)
        // {
        //     mid = (xLow+xHigh)/2;
        //     if(target == matrix[0][mid]) return true;
        //     else if(target>matrix[0][mid]) xLow = mid+1;
        //     else xHigh = mid-1;
        // }
        // if(xHigh<0) return false;
        // int y = xHigh;
        // xLow = 0;
        // xHigh = matrix.size()-1;
        // while(xLow<=xHigh)
        // {
        //     mid = (xLow+xHigh)/2;
        //     if(target == matrix[mid][y]) return true;
        //     else if(target>matrix[mid][y]) xLow = mid+1;
        //     else xHigh = mid-1;
        // }

        // if(xHigh<0) return false;
        // int x = xHigh;
        // xLow = ((x+y)>(matrix.size()-1))?(matrix.size()-1):(x+y);
        // xHigh = (x+y)-xLow;
        // while(xHigh<matrix[0].size() && xHigh<=(x+y))
        // {
        //     if(matrix[xLow][xHigh]==target) return true;
        //     else {xLow--;xHigh++;}
        // }
        // if((x+1)>=matrix.size()) return false;
        // xLow = ((x+y+1)>(matrix.size()-1))?(matrix.size()-1):(x+y+1);
        // xHigh = (x+y+1)-xLow;
        // while(xHigh<matrix[0].size() && xHigh<=(x+y+1))
        // {
        //     if(matrix[xLow][xHigh]==target) return true;
        //     else {xLow--;xHigh++;}
        // }
        // return false;

        
        // xLow = 0;
        // xHigh = matrix.size()-1;
        // while(xLow<=xHigh)
        // {
        //     mid = (xLow+xHigh)/2;
        //     if(target == matrix[mid][0]) return true;
        //     else if(target>matrix[mid][0]) xLow = mid+1;
        //     else xHigh = mid-1;
        // }
        // if(xHigh<0) return false;
        // y = xHigh;
        // xLow = 0;
        // xHigh = matrix[0].size()-1;
        // while(xLow<=xHigh)
        // {
        //     mid = (xLow+xHigh)/2;
        //     if(target == matrix[y][mid]) return true;
        //     else if(target>matrix[y][mid]) xLow = mid+1;
        //     else xHigh = mid-1;
        // }
        // return false;

        if(matrix.size()==0 || matrix[0].size()==0)
            return false;
        int x = matrix[0].size()-1;
        int y = 0;
        while(x>=0 && y<matrix.size())
        {
            if(target == matrix[y][x]) return true;
            else if(target > matrix[y][x]) y++;
            else x--;
        }
        return false;
    }
};