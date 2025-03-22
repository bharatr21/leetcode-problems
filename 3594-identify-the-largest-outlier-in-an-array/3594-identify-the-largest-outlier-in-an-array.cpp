class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> mp;
        int rsum = 0, out = -1001, n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = i;
            rsum += nums[i];
        }
        // sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i < n; i++) {
            if(mp.count(rsum - 2 * nums[i]) && mp[rsum - 2 * nums[i]] != i) 
                out = max(out, rsum - 2 * nums[i]);
        }
        return out;
    }
};