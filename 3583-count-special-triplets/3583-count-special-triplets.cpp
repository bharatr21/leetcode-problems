class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> freq, lfreq;
        int n = nums.size();
        lfreq.reserve(n * 2);
        for(int el: nums) freq[el]++;
        int res = 0;
        for(int el: nums) {
            int tgt = el * 2;
            int lc = lfreq[tgt];
            lfreq[el]++;
            int rc = freq[tgt] - lfreq[el];
            res = (res + (lc * 1LL * rc % MOD)) % MOD;
        }
        return res;
    }
};