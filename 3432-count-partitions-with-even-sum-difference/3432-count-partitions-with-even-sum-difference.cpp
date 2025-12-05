class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0, rsum = tot, res = 0, n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            lsum += nums[i];
            rsum -= nums[i];
            if(!(abs(rsum - lsum) % 2)) res++;
        }
        return res;
    }
};