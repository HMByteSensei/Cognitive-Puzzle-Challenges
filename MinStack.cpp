#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <stack>

static const bool __boost = [](){
    cin.tie( nullptr );
    cout.tie( nullptr );
    return ios_base::sync_with_stdio( false );
}();


class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    MinStack() {}

    void push(int val) {
        mainStack.push(val);
        // If minStack is empty or val is less than or equal to the current minimum, push it to minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        // If the top of mainStack is the same as the top of minStack, pop from minStack as well
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
