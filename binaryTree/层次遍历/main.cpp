#include <iostream>
using namespace std;
#include <queue>
#include <vector>

//返回空容器： vector<int>()  或者  {}

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode* > q;
        vector<int> v;
        TreeNode* p = root;
        q.push(p);
        while(!q.empty())
        {
            p = q.front();
            v.push_back(p->val);
            q.pop();
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        return v;
    }
};
