class Solution {
public:
    int sumd(int n) {
        int tmp = n, res = 0;
        while(tmp) {
            res += (tmp % 10);
            tmp = (tmp / 10);
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size(), mx = -1;
        vector<vector<int>> dsums(82, vector<int>()); 
        for(int n: nums) dsums[sumd(n)].push_back(n);
        for(int i = 1; i <= 81; i++) {
            if(dsums[i].size() >= 2) {
                sort(dsums[i].begin(), dsums[i].end(), greater<int>());
                mx = max(mx, dsums[i][0] + dsums[i][1]);
            }
        }
        return mx;
    }
};