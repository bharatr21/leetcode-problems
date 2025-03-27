class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> qnums(n);
        for(int i = 0; i < n; i++) {
            qnums[i] = (a * nums[i] * nums[i] + b * nums[i] + c);
        }
        sort(qnums.begin(), qnums.end());
        return qnums;
    }
};