// #1381: Design a Stack with Increment Operation
//
// Rowan Tran
//
// Design a stack which supports the following operations.
//
// Implement the CustomStack class:
//     CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of
//       elements in the stack or do nothing if the stack reached the maxSize.
//     void push(int x) Adds x to the top of the stack if the stack hasn't reached the maxSize.
//     int pop() Pops and returns the top of stack or -1 if the stack is empty.
//     void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are
//       less than k elements in the stack, just increment all the elements in the stack.

#include <vector>

class CustomStack {
private:
    int* data;
    size_t maxSize;
    size_t currentSize;

public:
    CustomStack(int maxSize) : maxSize(maxSize), currentSize(0) {
        data = new int[maxSize];
    }
    
    void push(int x) {
        // currentSize is also the first non-used index, so we insert at that index then increment.
        if (currentSize < maxSize) {
            data[currentSize++] = x;
        }
    }
    
    int pop() {
        // Since currentSize is the first non-used index, we want to return whatever is at index
        // currentSize-1, then also decrease currentSize, so the pre-decrement operator works for
        // this purpose.
        if (currentSize > 0) {
            return data[--currentSize];
        } else {
            return -1;
        }
    }
    
    void increment(int k, int val) {
        for (size_t i = 0; (i < k) && (i < currentSize); ++i) {
            data[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
