class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size(), i, end = 0;
        long int res = 0;
        if(n == 1) return customers[0][1];
        int farr = customers[0][0], fwt = customers[0][1];
        res += fwt;
        end = farr + fwt;
        for(i = 1; i < n; i++) {
            int arr = customers[i][0], wt = customers[i][1];
            res += max(0, end - arr) + wt;
            end = max(end, arr) + wt;
        }
        return (1.0 * res) / n;
    }
};