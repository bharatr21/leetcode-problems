class CustomStack {
public:
    vector<int> stk;
    int cap;
    CustomStack(int maxSize) {
        cap = maxSize;
    }
    
    void push(int x) {
        if(stk.size() == cap) return;
        stk.push_back(x);
    }
    
    int pop() {
        if(stk.empty()) return -1;
        int x = stk.back();
        stk.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        int n = stk.size();
        for(int i = 0; i < min(k, n); i++) stk[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */