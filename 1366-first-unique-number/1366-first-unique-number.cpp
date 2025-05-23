class FirstUnique {
public:
    unordered_map<int, int> fre;
    queue<int> q;
    FirstUnique(vector<int>& nums) {
        for(int n: nums) {
            fre[n]++;
            q.push(n);
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && fre[q.front()] > 1) q.pop();
        return (q.empty() ? -1: q.front());
    }
    
    void add(int value) {
        fre[value]++;
        q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */