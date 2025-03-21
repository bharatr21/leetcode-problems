class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int el = nums[i], ct = 0;
                do {
                    el = nums[el];
                    ct++;
                    vis[el] = true;
                } while(el != nums[i]);
                res = max(res, ct);
            }
        }
        return res;
    }
};