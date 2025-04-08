class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        int tgt = sum / 2, n = nums.size();
        vector<bool> prev(tgt + 1, false), cur(tgt + 1, false);
        for(int i = n - 2; i >= 0; i--)
        {
            prev[0] = true;
            for(int j = 1; j <= tgt; j++) 
            {
                cur[j] = cur[j] | prev[j];
                if(nums[i+1] <= j) cur[j] = cur[j] | prev[j - nums[i+1]];
            }
            prev = cur;
        }
        return prev[tgt];
    }
};