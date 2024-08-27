class Solution {
public:
    vector<int> pre;
    Solution(vector<int>& w) {
        for(auto el: w) {
            pre.push_back(el + (pre.empty() ? 0 : pre.back()));
        }
    }
    
    int pickIndex() {
        int n = pre.back();
        float idx_closest = ((float)rand() / RAND_MAX) * n;
        return lower_bound(pre.begin(), pre.end(), idx_closest) - pre.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */