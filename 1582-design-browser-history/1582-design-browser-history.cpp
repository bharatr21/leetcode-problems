class BrowserHistory {
public:
    vector<string> urls;
    int cur, last;
    BrowserHistory(string homepage) {
        urls.push_back(homepage);
        cur = 0;
        last = 0;
    }
    
    void visit(string url) {
        cur++;
        if(urls.size() > cur) {
            urls[cur] = url;
        } else {
            urls.push_back(url);
        }
        last = cur;
    }
    
    string back(int steps) {
        cur = max(0, cur - steps);
        return urls[cur];
    }
    
    string forward(int steps) {
        cur = min(last, cur + steps);
        return urls[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */