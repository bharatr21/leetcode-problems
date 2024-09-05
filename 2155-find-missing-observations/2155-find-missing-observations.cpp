class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> res;
        int m = rolls.size();
        int asum = accumulate(rolls.begin(), rolls.end(), 0);
        int miss = mean * (m + n) - asum;
        if(miss > 6 * n || miss < n) return res;
        while(miss) {
            int rem_size = n - res.size();
            if(miss/rem_size < 6) {res.push_back(miss / rem_size); miss -= miss/rem_size;}
            else {res.push_back(6); miss -= 6;}
        }
        return res;
    }
};