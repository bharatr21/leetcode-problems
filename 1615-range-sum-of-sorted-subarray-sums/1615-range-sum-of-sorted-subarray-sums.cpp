class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        int cursum = 0;
        int MOD = 1e9 + 7;
        for(int i = 0; i < n; i++)
        {
            cursum = nums[i];
            sums.push_back(cursum);
            for(int j = i+1; j < n; j++) {
                cursum += nums[j];
                sums.push_back(cursum);
            }
        }
        sort(sums.begin(), sums.end());
        vector<long int> pre(sums.size() + 1);
        pre[0] = 0;
        for(int i = 0; i < sums.size(); i++) {
            pre[i+1] = pre[i] + sums[i];
        }
        return (pre[right] - pre[left - 1]) % MOD;
    }
};