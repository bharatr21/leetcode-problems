class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int numz = 0, st = 0, en = 0, mx = 0;
        for(int en = 0; en < n; en++) {
            if(nums[en] == 0) numz++;
            while(numz > k) {
                if(nums[st] == 0) numz--;
                st++;
            }
            mx = max(mx, en - st + 1);
        }
        return mx;
    }
};