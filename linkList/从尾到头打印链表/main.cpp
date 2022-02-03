#include <iostream>
using namespace std;
#include <stack>
#include <vector>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> v;
        stack<int> s;
        ListNode* ptr = head;
        while (ptr)
        {
            s.push(ptr->val);
            ptr = ptr->next;
        }
        while (!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};

int main()
{

}