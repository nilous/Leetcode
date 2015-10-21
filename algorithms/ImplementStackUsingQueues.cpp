/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

#include <queue>

class Stack {
    std::queue<int> q_;
    int top_;  // 增加一个变量，将top()操作的时间复杂度从O(n)变为O(1)

public:
    // Push element x onto stack.
    void push(int x) {
        top_ = x;
        q_.push(x); 
    }

    // Removes the element on top of the stack.
    void pop() {
        std::queue<int> q;
        while (q_.size() > 1) {
            top_ = q_.front();
            q.push(top_);
            q_.pop();
        }
        q_ = q;
    }

    // Get the top element.
    int top() {
       return top_; 
    }

    // Return whether the stack is empty.
    bool empty() {
        return q_.empty();
    }
};

#include <iostream>

int main(int argc, char **argv) {
    Stack stack;
    std::cout << (stack.empty() ? "empty" : "filled") << '\n';
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.top() << '\n';
    stack.pop();
    std::cout << stack.top() << '\n';
    std::cout << (stack.empty() ? "empty" : "filled") << '\n';
    return 0;
}
