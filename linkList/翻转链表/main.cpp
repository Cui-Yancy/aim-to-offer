#include <iostream>
using namespace std;
#include <stack>


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prior = NULL;
        ListNode* next = NULL;
        while (head)
        {
            next = head->next;
            head->next = prior;
            prior = head;
            head = next;
        }
        return prior;
    }
};
int main()
{

}