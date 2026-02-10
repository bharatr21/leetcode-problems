class Solution {
public:
    bool isBal(vector<int>& nums, int st, int en) {
        unordered_set<int> ev, od;
        for(int i = st; i <= en; i++) {
            if(nums[i] % 2) od.insert(nums[i]);
            else ev.insert(nums[i]);
        }
        return (od.size() == ev.size());
    }

    int longestBalanced(vector<int>& nums) {
        int mx = 0, n = nums.size();
        bool flag = false;
        for(int sz = n - 1; sz > 0; sz--) {
            for(int i = 0; i + sz < n; i++) {
                if(isBal(nums, i, i + sz)) {
                    mx = sz + 1;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        return mx;
    }
};