class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        mp[val] = (int)v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        int idx = mp[val];
        if(idx != v.size() - 1) {
            mp[v.back()] = idx;
            swap(v[idx], v.back());
        }
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        return v[rand() % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */