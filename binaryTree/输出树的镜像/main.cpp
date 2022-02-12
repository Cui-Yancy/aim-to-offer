﻿#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* p = root->left;
        root->left = root->right;
        root->right = p;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};