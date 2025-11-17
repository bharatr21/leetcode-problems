class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> idxs;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) idxs.push_back(i);
        }
        int m = idxs.size();
        bool res = true;
        for(int i = 1; i < m; i++) {
            if(idxs[i] - idxs[i-1] <= k) {
                res = false; 
                break;
            }
        }
        return res;
    }
};