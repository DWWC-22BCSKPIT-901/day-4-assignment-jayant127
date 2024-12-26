#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack; // Main stack to store all elements
    stack<int> minStack;  // Auxiliary stack to store minimums

public:
    MinStack() {
        // Constructor initializes empty stacks
    }

    void push(int val) {
        mainStack.push(val);
        // Push to minStack only if it's empty or the value is less than or equal to the current minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;

    // Example operations
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "getMin(): " << minStack.getMin() << endl; // Output: -3

    minStack.pop();
    cout << "top(): " << minStack.top() << endl;    // Output: 0
    cout << "getMin(): " << minStack.getMin() << endl; // Output: -2

    return 0;
}
