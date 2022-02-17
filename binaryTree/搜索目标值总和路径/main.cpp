#include <iostream>
using namespace std;
#include <stack>
#include <vector>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        firstReverse(root,target);
        return ret;
    }

    vector<vector<int>> ret;
    vector<int> tmp;
    void firstReverse(TreeNode* root, int sum)
    {
        if(!root) return;
        sum -= root->val;
        tmp.push_back(root->val);
        if(sum==0 && !root->left && !root->right)
        {
            ret.push_back(tmp);
        }
        firstReverse(root->left,sum);
        firstReverse(root->right,sum);
        tmp.pop_back();
    }
};