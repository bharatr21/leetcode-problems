class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0, n = nums.size(), ct = 0;
        for(int el: nums) mx = mx | el;
        for(int i = 0; i < (1 << n); i++) {
            int j = i, tmp = 0, idx = 0;
            while(j) {
                if(j & 1) tmp = tmp | nums[idx];
                j = j >> 1;
                idx++;
            }
            if(tmp == mx) ct++;
        }
        return ct;
    }
};