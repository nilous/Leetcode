#include <string.h>

// Actually, we should raise an exception if user
// call pop() while no element left in the stack.
template <typename T>
class Stack {
    T *data_;
    size_t size_;
    size_t capacity_;

    void reallocMemory(size_t newCapacity) {
        if (newCapacity < size_) return;

        T *tmp = new T[newCapacity];
        memcpy(tmp, data_, sizeof(T)*size_);

        delete[] data_;
        data_ = tmp;
        capacity_ = newCapacity;
    }
public:
    static const size_t kDefaultCapacity = 16; 

    explicit Stack(int capacity = kDefaultCapacity)
        : data_(0),
          size_(0),
          capacity_(0) {
        reallocMemory(kDefaultCapacity);
    }

    ~Stack() { delete[] data_; }

    size_t size() const { return size_; }

    void push(const T &elem) {
        if (size_ == capacity_)
            reallocMemory(capacity_*2);
        data_[size_++] = elem;
    }

    void pop() {
        size_--;
    }

    T top() {
        return data_[size_-1];
    }

};

class MinStack {
    Stack<int> stack_;
    Stack<int> minStack_;

public:
    void push(int x) {
        stack_.push(x);
        if (minStack_.size() == 0 || x <= minStack_.top())
            minStack_.push(x);
    }

    void pop() {
        if (stack_.top() == minStack_.top())
            minStack_.pop();
        stack_.pop();
    }

    int top() {
        return stack_.top();
    }
        
    int getMin() {
        return minStack_.top();
    }
};
