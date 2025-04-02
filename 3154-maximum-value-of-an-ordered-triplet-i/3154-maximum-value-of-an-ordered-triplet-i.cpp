class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size(), i, j, k;
        long long mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    mx = max(1LL * mx, 1LL * (nums[i] - nums[j]) * nums[k] * 1LL);
                }
            }
        }
        return mx;
    }
};