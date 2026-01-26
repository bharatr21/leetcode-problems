class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mn = 2000001;
        for(int i = 0; i < n - 1; i++) {
            mn = min(mn, arr[i+1] - arr[i]);
        }
        for(int i = 0; i < n - 1; i++) {
            if(arr[i+1] - arr[i] == mn) {
                res.push_back({arr[i], arr[i+1]});
            }
        }
        return res;
    }
};