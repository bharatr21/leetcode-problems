class Vector2D {
public:
    vector<int> store;
    int pos;
    Vector2D(vector<vector<int>>& vec) {
        for(auto v: vec) {
            for(auto el: v) {
                store.push_back(el);
            }
        }
        pos = 0;
    }
    
    int next() {
        return store[pos++];
    }
    
    bool hasNext() {
        return (pos < store.size());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */