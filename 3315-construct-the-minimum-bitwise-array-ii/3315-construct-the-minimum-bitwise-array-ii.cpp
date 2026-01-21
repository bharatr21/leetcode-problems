class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            int el = nums[i];
            if(el % 2) {
                int z = (el ^ (el+1)) + 1 >> 2;
                int x = el ^ z;
                ans[i] = x;
            }
        }
        return ans;
    }
};