class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int numz = 0, mx = 0, n = nums.size();
        int st = 0, en = 0;
        while(en < n) {
            if(nums[en] == 0) numz++; 
            en++;
            while(numz > k) {
                if(nums[st] == 0) numz--;
                st++;
            }
            mx = max(mx, en - st);
        }
        return mx;
    }
};