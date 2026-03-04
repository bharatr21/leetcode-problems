class MinStack {
public:
    stack<pair<int, int>> stk;
    int mn;
    MinStack() {
    }
    
    void push(int val) {
        int mn = (stk.empty() ? val : stk.top().second);
        if(val <= mn) mn = val;
        stk.push({val, mn});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */