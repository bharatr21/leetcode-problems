class FirstUnique {
public:
    unordered_map<int, bool> uniq;
    queue<int> q;
    FirstUnique(vector<int>& nums) {
        for(int n: nums) {
            if(!uniq.count(n)) {
                uniq[n] = true;
                q.push(n);
            }
            else if(uniq[n]) uniq[n] = false;
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && uniq.count(q.front()) && !uniq[q.front()]) q.pop();
        return (q.empty() ? -1 : q.front());
    }
    
    void add(int value) {
        if(!uniq.count(value)) {
            uniq[value] = true;
            q.push(value);
        }
        else if(uniq[value]) uniq[value] = false;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */