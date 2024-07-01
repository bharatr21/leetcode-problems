class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size(), i, j;
        if(n < 3) return false;
        for(i = 2; i < n; i++) {
            j = i - 2;
            if((arr[j] % 2) && (arr[j+1] % 2) && (arr[j+2] % 2)) return true;
        }
        return false;
    }
};