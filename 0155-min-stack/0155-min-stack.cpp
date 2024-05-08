class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {}
    
    void push(int val) {
        int cur_min = ((st.empty()) ? INT_MAX : st.top().second);
        if(st.empty() || (val < cur_min))
        {
            st.push({val, val});
        }
        else
        {
            st.push({val, cur_min});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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