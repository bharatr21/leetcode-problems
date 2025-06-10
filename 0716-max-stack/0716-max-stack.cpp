class MaxStack {
public:
    set<pair<int, int>> val;
    set<pair<int, int>> id;
    int ct;
    MaxStack() {
        ct = 0;
    }
    
    void push(int x) {
        val.insert({x, ct});
        id.insert({ct, x});
        ct++;
    }
    
    int pop() {
        auto [ct, x] = *(--id.end());
        id.erase(--id.end());
        val.erase(val.find({x, ct}));
        return x;
    }
    
    int top() {
        return (--id.end())->second;
    }
    
    int peekMax() {
        return (--val.end())->first;
    }
    
    int popMax() {
        auto [x, ct] = *(--val.end());
        val.erase(--val.end());
        id.erase(id.find({ct, x}));
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