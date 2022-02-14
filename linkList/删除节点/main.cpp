#include <iostream>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return NULL;                  //输入空链表时，返回空
        if(head->val==val) return head->next;   //首结点为删除值时，直接返回next
        ListNode* p = head;
        ListNode* pri = NULL;
        while(p)
        {
            if(p->val==val)
                pri->next = p->next;
            pri = p;
            p = p->next;
        }
        return head;
    }
};