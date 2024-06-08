class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), i;
        int premod = 0;
        unordered_map<int, int> mp;
        if(n == 1) return false;
        mp[0] = -1;
        for(i = 0; i < n; i++)
        {
            premod = (premod + nums[i]) % k;
            if(mp.find(premod) != mp.end()) {
                if(i - mp[premod] >= 2) return true;
            }
            else mp[premod] = i;
        }
        return false;
    }
};