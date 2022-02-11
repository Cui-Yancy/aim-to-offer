#include <iostream>
using namespace std;
#include <queue>
#include <vector>

//层次遍历，每一层单独形成数组
//队列操作，每一层打印时，以队列长度做for循环push_back

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // if(!root) return {};
        // vector<vector<int>> v;
        // vector<int> v2;
        // queue<pair<TreeNode*,int>> q;
        // TreeNode* p = root;
        // q.push(pair(p,1));
        // int index = 1;
        // int num = 0;
        // while(!q.empty())
        // {
        //     p = q.front().first;
        //     num = q.front().second;
        //     if(num!=index)
        //     {
        //         v.push_back(v2);
        //         v2.clear();
        //         index++;
        //     }
        //     q.pop();
        //     v2.push_back(p->val);
        //     if(p->left) q.push(pair(p->left,num+1));
        //     if(p->right) q.push(pair(p->right,num+1));
        // }
        // v.push_back(v2);
        // return v;

        if(!root) return {};
        vector<vector<int>> v;
        queue<TreeNode*> q;
        TreeNode* p = root;
        q.push(p);
        while(!q.empty())
        {
            vector<int> tmp;
            for(int i=q.size(); i>0; i--)
            {
                p = q.front();
                tmp.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                q.pop();
            }
            v.push_back(tmp);
        }
        return v;
    }
};