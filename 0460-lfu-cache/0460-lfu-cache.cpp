class LFUCache {
public:
    unordered_map<int, int> kv;
    unordered_map<int, int> kf;
    unordered_map<int, list<int>::iterator> key2it;
    unordered_map<int, list<int>> freq2keys;

    int cap;
    int minf;
    LFUCache(int capacity) {
        cap = capacity;
        minf = capacity;
    }
    
    int get(int key) {
        if(!kv.count(key)) return -1;
        int val = kv[key];
        int f = kf[key];
        kf[key] = f + 1;
        freq2keys[f].erase(key2it[key]);
        if(freq2keys[f].empty()) {
            freq2keys.erase(f);
            if(minf == f) minf = f + 1;
        }
        if(!freq2keys.count(f+1)) freq2keys[f+1] = {};
        freq2keys[f+1].push_front(key);
        key2it[key] = freq2keys[f+1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if(kv.count(key)) {
            int f = kf[key];
            kf[key] = f + 1;
            kv[key] = value;
            freq2keys[f].erase(key2it[key]);
            if(freq2keys[f].empty()) {
                freq2keys.erase(f);
                if(minf == f) minf = f + 1;
            }
            if(!freq2keys.count(f+1)) freq2keys[f+1] = {};
            freq2keys[f+1].push_front(key);
            key2it[key] = freq2keys[f+1].begin();
        } else {
            if(kv.size() == cap) {
                int rmkey = freq2keys[minf].back();
                freq2keys[minf].pop_back();
                key2it.erase(rmkey);
                kf.erase(rmkey);
                kv.erase(rmkey);
            }
            freq2keys[1].push_front(key);
            kv[key] = value;
            kf[key] = 1;
            key2it[key] = freq2keys[1].begin();
            minf = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */