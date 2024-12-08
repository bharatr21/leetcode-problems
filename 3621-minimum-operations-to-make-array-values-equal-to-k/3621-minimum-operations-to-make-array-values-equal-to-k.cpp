class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res = 0;
        bool flag = false;
        for (int el : nums)
            mp[el]++;
        for (auto u : mp) {
            if(u.first > k) res++;
            else if(u.first < k) return -1;
        }
        return res;
    }
};