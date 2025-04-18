class MaxStack {
public:
    set<pair<int, int>> st;
    set<pair<int, int>> val;
    int ct;
    MaxStack() {
        ct = 0;
    }
    
    void push(int x) {
        st.insert({ct, x});
        val.insert({x, ct});
        ct++;
    }
    
    int pop() {
        auto [ct, x] = *st.rbegin();
        st.erase(prev(st.end()));
        val.erase(val.find({x, ct}));
        return x;
    }
    
    int top() {
        return st.rbegin()->second;
    }
    
    int peekMax() {
        return val.rbegin()->first;
    }
    
    int popMax() {
        auto [x, ct] = *val.rbegin();
        val.erase(prev(val.end()));
        st.erase(st.find({ct, x}));
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */