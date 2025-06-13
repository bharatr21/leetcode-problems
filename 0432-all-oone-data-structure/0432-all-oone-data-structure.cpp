

class AllOne {
public:
    struct Node {
        int freq;
        unordered_set<string> keys;
    };

    list<Node> freql;
    unordered_map<string, list<Node>::iterator> key2it;
    AllOne() {
        
    }
    
    void inc(string key) {
        auto it = key2it.count(key) ? key2it[key] : freql.insert(freql.begin(), Node{0, {}});
        int f = it->freq;
        auto nextIt = next(it);
        if(nextIt == freql.end() || nextIt->freq != f + 1)
            nextIt = freql.insert(nextIt, Node{f+1, {}});
        nextIt->keys.insert(key);
        key2it[key] = nextIt;
        it->keys.erase(key);
        if(it->keys.empty()) freql.erase(it);
    }
    
    void dec(string key) {
        auto mapit = key2it.find(key);
        if(mapit == key2it.end()) return;
        auto it = mapit->second;
        int f = it->freq;
        if(f > 1) {
            auto prevIt = (it == freql.begin()) ? freql.end() : prev(it);
            if(prevIt == freql.end() || prevIt->freq != f - 1) {
                prevIt = freql.insert(it, Node{f-1, {}});
            }
            prevIt->keys.insert(key);
            key2it[key] = prevIt;
        } else key2it.erase(mapit);
        it->keys.erase(key);
        if(it->keys.empty()) freql.erase(it);
    }
    
    string getMaxKey() {
        auto sset = (--freql.end())->keys.begin();
        return *sset;
    }
    
    string getMinKey() {
        auto sset = (freql.begin())->keys.begin();
        return *sset;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */