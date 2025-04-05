class MyStack {
public:
    queue<int> q1, q2;
    int tope;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        tope = x;
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int el = q1.front();
        q1.pop();
        if(!q1.empty()) tope = q1.front();
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