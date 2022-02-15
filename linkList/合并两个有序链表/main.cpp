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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // if(!l1) return l2;
        // if(!l2) return l1;
        // if(l1->val > l2->val) {l2->next = mergeTwoLists(l1, l2->next); return l2;}
        // else{l1->next = mergeTwoLists(l1->next, l2); return l1;}

        ListNode* p1=l1;
        ListNode* p2=l2;
        ListNode* p =new ListNode(0);
        ListNode* ret = p;
        while(p1 && p2)
        {
            if(p1->val < p2->val) {
                p->next = p1;
                p = p->next;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p = p->next;
                p2 = p2->next;
            }
        }
        if(!p1) p->next = p2;
        else p->next = p1;
        return ret->next;
    }
};