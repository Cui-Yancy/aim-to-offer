#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

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
        if(!root) return {};
        vector<vector<int>> v;
        queue<TreeNode* > q;
        TreeNode * p = root;
        int index = 1;
        q.push(p);
        while(!q.empty())
        {
            vector<int> tmp;
            for(int i=q.size();i>0;i--)
            {
                p = q.front();
                tmp.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                q.pop();
            }
            if(!(index%2)) reverse(tmp.begin(),tmp.end());
            index++;
            v.push_back(tmp);
        }
        return v;
    }
};