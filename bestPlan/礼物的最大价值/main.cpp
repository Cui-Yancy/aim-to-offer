#include <vector>
#include <iostream>
using namespace std;

//求最大值路径
//从左上角到第(i,j)点的最大值路径为：从(i-1,j)和(i,j-1)两个点的最大值路径中选取最大值，加上(i,j)的值即可

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        //初始化第一列
        for(int i=1; i<grid.size(); i++)
            grid[i][0] += grid[i-1][0];

        //初始化第一行
        for(int i=1; i<grid[0].size(); i++)
            grid[0][i] += grid[0][i-1];

        //求其它行列的值
        for(int i=1; i<grid.size() ;i++)
            for(int j = 1; j <grid[0].size(); j++)
                grid[i][j] += (grid[i][j-1]>grid[i-1][j]?grid[i][j-1]:grid[i-1][j]);
        return grid[grid.size()-1][grid[0].size()-1];
    }
};