#include <iostream>
#include <stack>

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        
        if (auxStack.empty() || val < auxStack.top().first) {
            auxStack.push({val, 1});
        } else if (val == auxStack.top().first) {
            auxStack.top().second++;
        }
    }
    
    void pop() {
        if (auxStack.top().first == mainStack.top()) {
            auxStack.top().second--;
            if (auxStack.top().second == 0) {
                auxStack.pop();
            }
        }

        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return auxStack.top().first;
    }
private:
    std::stack<std::pair<int, int>> auxStack;
    std::stack<int> mainStack;
};

int main() {}