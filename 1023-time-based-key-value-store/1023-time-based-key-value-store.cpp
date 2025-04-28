class TimeMap {
public:
    unordered_map<string, vector<string>> store;
    unordered_map<string, vector<int>> timer;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back(value);
        timer[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(!timer.count(key)) return "";
        auto ub = upper_bound(timer[key].begin(), timer[key].end(), timestamp);
        if(ub == timer[key].begin() && *ub > timestamp || *prev(ub) > timestamp) return "";
        int idx = ((ub == timer[key].begin()) ? 0 : prev(ub) - timer[key].begin());
        return store[key][idx];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */