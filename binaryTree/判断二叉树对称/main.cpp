#include <iostream>
using namespace std;
//#include <vector>

//如果使用中序遍历产生顺序表，这个表对称并不能说明二叉树对称
//对称时，根节点的左右结点值相等，左节点的左节点，和右节点的右节点相等
//左节点的右节点，和右节点的左节点相等

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return circule(root->left,root->right)
    }

    bool circule(TreeNode* A, TreeNode* B)
    {
        if(!A && !B) return true;   //最终递归到两侧都为叶子结点时，返回真
        if(!A || !B || A->val!=B->val) return false;    //如果某一个结点为空，另一个不为空，或者左右值不相等，返回假
        return circule(A->left,B->right) && circule(A->right,B->left);
    }
};