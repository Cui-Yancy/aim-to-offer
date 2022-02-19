#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        pre = NULL;
        midTraverse(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    Node* head, *pre;
    void midTraverse(Node* root)
    {
        if(!root) return;
        midTraverse(root->left);
        if(!pre) head = root;       //第一次访问pre时，是最小结点，此时记录头结点
        else {root->left = pre; pre->right = root;}
        pre = root;
        midTraverse(root->right);
    }
};