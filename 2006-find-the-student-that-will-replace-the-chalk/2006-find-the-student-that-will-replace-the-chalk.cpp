class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long sum = 0;
        for(int el: chalk) sum += el;
        vector<long> pre(n+1, 0);
        for(int i = 1; i <= n; i++) {
            pre[i] = pre[i-1] + chalk[i-1];
        }
        int idx = lower_bound(pre.begin(), pre.end(), k % sum) - pre.begin();
        return ((pre[idx] == k % sum) ? idx : idx - 1);
    }
};