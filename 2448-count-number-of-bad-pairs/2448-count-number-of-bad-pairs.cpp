class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int, int> diffs;
        for(int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            ans += i - (diffs[diff]);
            diffs[diff]++;
        }
        return ans;
    }
};