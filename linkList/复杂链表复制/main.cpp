#include <iostream>
using namespace std;
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // if(!head)
        // {
        //     return NULL;
        // }
        // unordered_map<Node*,Node*> map;
        // Node* p = head;
        // while(p)
        // {
        //     map[p] = new Node(p->val);
        //     p = p->next;
        // }

        // p = head;
        // while(p)
        // {
        //     map[p]->next = map[p->next];
        //     map[p]->random = map[p->random];
        //     p = p->next;
        // }
        // return  map[head];

        if(!head) return NULL;
        Node* p = head, *next, *ptr;
        while(p)
        {
            next = p->next;
            ptr = new Node(p->val);
            ptr->next = next;
            p->next = ptr;
            p = next;
        }

        p = head;
        while(p)
        {
            if(p->random)   //如果随机指针非空才需要指向复制结点
                p->next->random = p->random->next;
            p = p->next->next;
        }

        p = head;
        ptr = p->next;
        while(p)
        {
            next = p->next;
            p->next = p->next->next;
            if(p->next)     //尾结点处，复制链表不需要重新链接
                next->next = p->next->next;
            p = p->next;
        }
        return ptr;
    }
};