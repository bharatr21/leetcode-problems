class MyStack {
public:
    queue<int> q1, q2;
    int tope;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        tope = x;        
    }
    
    int pop() {
        if(q2.empty()) {
            while(q1.size() > 1) {
                tope = q1.front();
                q2.push(q1.front());
                q1.pop();
            }
        }
        int el = q1.front();
        q1.pop();
        swap(q1, q2);
        return el;
    }
    
    int top() {
        return tope;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */