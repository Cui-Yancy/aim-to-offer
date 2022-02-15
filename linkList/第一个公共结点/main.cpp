#include <iostream>
using namespace std;
#include <unordered_map>

//双指针寻找第一个公共结点
//两个指针分别从A和B头结点开始后移，到达尾结点时，再交换头结点后移
//如果有公共结点，必定会在某一后移步骤中相等
//如果第二次移动到某一链表尾结点仍然没有相等，此时两个指针都位于尾结点，那么就是没有公共结点

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_map<ListNode*, int>  map;
        // ListNode* p1 = headA;
        // ListNode* p2 = headB;
        // while(p1 || p2)
        // {
        //     if(p1 && map[p1]!=1) {map[p1]=1; p1 = p1->next;}
        //     else if(map[p1]==1)return p1;
        //     if(p2 && map[p2]!=1) {map[p2]=1; p2 = p2->next;}
        //     else if(map[p2]==1)return p2;
        // }
        // return NULL;

        if(!headA || !headB) return NULL;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        bool firstTail = false;
        while(p1 != p2 && p1 && p2)
        {
            p1 = p1->next;
            p2 = p2->next;
            if(!p1)
            {
                if(firstTail) return NULL;
                else{p1 = headB; firstTail = true;}
            }
            if(!p2) p2 = headA;
        }
        return p1;
    }
};