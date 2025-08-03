class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> forw(n, 0), back(n, 0);
        forw[0] = arr[0];
        back[n-1] = arr[n-1];
        for(int i = 1; i < n; i++) forw[i] = max(forw[i-1] + arr[i], arr[i]);
        int res = *max_element(forw.begin(), forw.end());
        for(int i = n - 2; i >= 0; i--) back[i] = max(back[i+1] + arr[i], arr[i]);
        for(int i = 1; i < n - 1; i++) {
            res = max(res, max(forw[i-1] + back[i+1], forw[i] + back[i+1]));
        }
        return res; 
    }
};