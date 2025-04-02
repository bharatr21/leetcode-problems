class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> res = nums;
        int n = res.size();
        while(n > 1) {
            for(int i = 0; i < n - 1; i++) {
                res[i] = (res[i] + res[i+1]) % 10;
            }
            n--;
        }
        return res[0];
    }
};