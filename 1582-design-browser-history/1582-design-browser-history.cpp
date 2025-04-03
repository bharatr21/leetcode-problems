class BrowserHistory {
public:
    stack<string> backst, forw;
    string cur;
    BrowserHistory(string homepage) {
        cur = homepage;
    }
    
    void visit(string url) {
        while(!forw.empty()) forw.pop();
        backst.push(cur);
        cur = url;
    }
    
    string back(int steps) {
        int tmp = steps;
        while(!backst.empty() && tmp) {
            tmp--;
            forw.push(cur);
            cur = backst.top();
            backst.pop();
        }
        return cur;
    }
    
    string forward(int steps) {
        int tmp = steps;
        while(!forw.empty() && tmp) {
            tmp--;
            backst.push(cur);
            cur = forw.top();
            forw.pop();
        }
        return cur;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */