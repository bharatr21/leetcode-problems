class RecentCounter {
public:
    vector<int> v;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        v.push_back(t);
        auto ub = upper_bound(v.begin(), v.end(), t - 3000);
        if(ub == v.begin()) return v.size();
        else return ((*prev(ub) == t - 3000) ? (v.size() - (prev(ub) - v.begin())) : (v.size() - 1 - (prev(ub) - v.begin())));
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */