class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), cur_sum = 0, res = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            cur_sum += nums[i];
            if(mp.count(cur_sum - k)) {
                res += mp[cur_sum - k];
            }
            mp[cur_sum]++;
        }
        return res;
    }
};