class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        int ct = 0, preSum = 0;
        int oddct = 0, evenct = 1;
        for(int el: arr) {
            preSum += el;
            if(preSum % 2) {
                ct += evenct;
                oddct++;
            } else {
                ct += oddct;
                evenct++;
            }
            ct = ct % MOD;
        }
        return ct;
    }
};