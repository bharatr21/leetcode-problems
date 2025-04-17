class MaxStack {
public:
    stack<pair<int, int>> st;
    priority_queue<pair<int, int>> pq;
    unordered_set<int> removed;
    int ct;
    MaxStack() {
        ct = 0;
    }
    
    void push(int x) {
        st.push({x, ct});
        pq.push({x, ct});
        ct++;
    }
    
    int pop() {
        while(removed.count(st.top().second)) st.pop();
        auto [el, ct] = st.top();
        st.pop();
        removed.insert(ct);
        return el;
    }
    
    int top() {
        while(removed.count(st.top().second)) st.pop();
        return st.top().first;
    }
    
    int peekMax() {
        while(removed.count(pq.top().second)) pq.pop();
        return pq.top().first;
    }
    
    int popMax() {
        while(removed.count(pq.top().second)) pq.pop();
        auto [el, ct] = pq.top();
        pq.pop();
        removed.insert(ct);
        return el;
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