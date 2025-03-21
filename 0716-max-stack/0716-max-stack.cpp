class MaxStack {
public:
    int cnt;
    set<pair<int, int>> stk;
    set<pair<int, int>> val;
    MaxStack() {
        cnt = 0;
    }
    
    void push(int x) {
        stk.insert({cnt, x});
        val.insert({x, cnt});
        cnt++;
    }
    
    int pop() {
        auto [cnt, x] = *stk.rbegin();
        stk.erase({cnt, x});
        val.erase({x, cnt});
        return x;
    }
    
    int top() {
        return stk.rbegin()->second;
    }
    
    int peekMax() {
        return val.rbegin()->first;
    }
    
    int popMax() {
        auto [cnt, x] = *val.rbegin();
        val.erase({cnt, x});
        stk.erase({x, cnt});
        return cnt;
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