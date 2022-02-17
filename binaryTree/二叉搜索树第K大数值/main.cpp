#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//
#include <vector>

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> v = lastSearch(root);
        return v[k-1];
    }

    vector<int> lastSearch(TreeNode* root)
    {
        if(!root) return {};
        vector<int> v(lastSearch(root->right));
        v.push_back(root->val);
        vector<int> tmp = lastSearch(root->left);
        v.insert(v.end(),tmp.begin(),tmp.end());
    }
};