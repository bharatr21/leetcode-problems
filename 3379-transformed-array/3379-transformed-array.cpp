class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> res;
        int cur = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                cur = (i + nums[i]) % n;
                res.push_back(nums[cur]);
            }
            else if(nums[i] < 0) {
                cur = ((i + nums[i]) % n + n) % n;
                res.push_back(nums[cur]);
            }
            else res.push_back(nums[i]);
        }
        return res;
    }
};