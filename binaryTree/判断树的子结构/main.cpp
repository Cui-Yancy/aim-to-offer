#include <iostream>
using namespace std;

//判断是否为子结构
//依次遍历每一个结点，判断值是否相等
//相等时判断子结构是否相同，不相等时递归向后判断

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B || !A) return false;
        if(A->val == B->val && isSub(A,B)) return true;
        // {
        //     if(!(B->left) && !(B->right)) return true;
        //     else if(B->left && !(B->right)) return isSubStructure(A->left,B->left);
        //     else if(!(B->left) && B->right) return isSubStructure(A->right,B->right);
        //     else return isSubStructure(A->left,B->left) && isSubStructure(A->right,B->right);
        // }
        else return isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }

    bool isSub(TreeNode* A, TreeNode* B)
    {
        if(!B || !A) return false;
        if(A->val == B->val)
        {
            if(!(B->left) && !(B->right)) return true;
            else if(B->left && !(B->right)) return isSub(A->left,B->left);
            else if(!(B->left) && B->right) return isSub(A->right,B->right);
            else return isSub(A->left,B->left) && isSub(A->right,B->right);
        }
        else return false;
    }
};