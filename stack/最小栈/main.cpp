#include <iostream>
using namespace std;
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minS.push(0x7fffffff);
    }

    void push(int x) {
        s.push(x);
        if (x <= minS.top())
        {
            minS.push(x);
        }
    }

    void pop() {
        if (s.top() == minS.top()) minS.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int min() {
        return minS.top();
    }

    stack<int> s;
    stack<int> minS;
};

int main()
{

}