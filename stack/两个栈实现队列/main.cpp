#include <iostream>
using namespace std;
#include <stack>

class CQueue {
public:
    CQueue() {
        len = 0;
    }

    void appendTail(int value) {
        s1.push(value);
        len++;
    }

    int deleteHead() {
        if (len <= 0)return -1;
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        len--;
        return val;
    }

    stack<int> s1;
    stack<int> s2;
    int len;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{

}