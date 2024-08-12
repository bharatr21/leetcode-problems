class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        int target = sum / 2;
        vector<int> cur(target+1, 0), next(target+1, 0);
        for(int i = 0; i <= n; i++) cur[0] = 1;
        for(int i = 1; i <= target; i++) next[i] = 0;
        for(int idx = n - 1; idx >= 0; idx--) {
            for(int j = 1; j <= target; j++) {
                if(nums[idx] <= j) {
                    cur[j] = (next[j - nums[idx]] || next[j]);
                }
                else {
                    cur[j] = next[j];
                }
            }
            next = cur;
        }        
        return cur[target];
    }
};