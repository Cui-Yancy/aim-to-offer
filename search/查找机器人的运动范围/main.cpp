#include <iostream>
using namespace std;

//m行n列的矩阵，机器人从[0,0出发]
//坐标各位之和不大于k
//问能进入几个格子

class Solution {
public:
    int movingCount(int m, int n, int k) {
        sumL = k;
        xL = m;
        yL = n;
        ret = 0;
        visitedInit();
        BFS(0,0);
        return ret;
    }

    int ret;
    int xL, yL, sumL;
    bool ** visited;

    //初始化标记数组，用于标记坐标是否被访问过
    void visitedInit()
    {
        visited = new bool*[xL];
        for(int i=0;i<xL;i++)
        {
            visited[i] = new bool[yL];
        }
        for(int i=0;i<xL;i++)
            for(int j=0;j<yL;j++)
                visited[i][j] = false;
    }

    void BFS(int x, int y)
    {
        //坐标在范围之外，或者坐标各位之和不在范围之内，或者坐标点已经访问过来
        if(x<0 || x>=xL || y<0 || y>=yL || visited[x][y] ||  !inLimit(x,y)) return;
        ret++;
        visited[x][y] = true;
        BFS(x+1,y);
        BFS(x-1,y);
        BFS(x,y+1);
        BFS(x,y-1);
    }

    //用于判断坐标值是否在范围之内
    bool inLimit(int x, int y)
    {
        int sum = 0;
        while(x)
        {
            sum += (x%10);
            x /= 10;
        }
        while(y)
        {
            sum += (y%10);
            y /= 10;
        }
        return (sum<=sumL)?true:false;
    }
};