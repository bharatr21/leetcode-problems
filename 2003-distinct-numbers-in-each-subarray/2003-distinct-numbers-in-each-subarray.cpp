class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        map<int, int> mp;
        for(int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }
        res.push_back(mp.size());
        for(int j = k; j < n; j++) {
            mp[nums[j]]++;
            if(--mp[nums[j-k]] == 0) mp.erase(nums[j-k]);
            res.push_back(mp.size());
        }
        return res;
    }
};