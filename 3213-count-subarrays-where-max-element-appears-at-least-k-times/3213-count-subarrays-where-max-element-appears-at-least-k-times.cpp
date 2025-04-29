class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size(), window = 0;
        int st = 0;
        long long res = 0;
        for(int en = 0; en < n; en++) {
            if(nums[en] == mx) window++;
            while(window == k) {
                if(nums[st] == mx) window--;
                st++;
            }
            res += st;
        }
        return res;
    }
};