class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int el: s) {
            if(!s.count(el - 1)) {
                int cur = el;
                int mx = 1;
                while(s.count(el + 1)) {
                    el++;
                    mx++;
                }
                res = max(res, mx);
            }
        }
        return res;
    }
};