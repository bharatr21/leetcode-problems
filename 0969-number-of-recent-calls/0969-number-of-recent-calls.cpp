class RecentCounter {
public:
    list<int> data;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        data.push_back(t);
        while(data.front() < t - 3000) data.pop_front();
        return data.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */