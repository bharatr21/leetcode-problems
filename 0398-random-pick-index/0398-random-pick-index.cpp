class Solution {
public:
    unordered_map<int, vector<int>> mp;
    Solution(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int idx = rand() % mp[target].size();
        return mp[target][idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */