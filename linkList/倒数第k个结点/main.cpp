#include <iostream>
using namespace std;
#include <stack>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // stack<ListNode*> stk;
        // ListNode* p=head;
        // while(p)
        // {
        //     stk.push(p);
        //     p = p->next;
        // }
        // if(k>stk.size()) return NULL;
        // for(int i=0; i<k-1; i++)
        //     stk.pop();
        // return stk.top();

        ListNode* p = head;
        int num = 0;
        while(p)
        {
            p = p->next;
            num ++;
        }
        if(k>num) return NULL;
        p = head;
        for(int i=0; i<(num-k); i++)
            p = p->next;
        return p;
    }
};