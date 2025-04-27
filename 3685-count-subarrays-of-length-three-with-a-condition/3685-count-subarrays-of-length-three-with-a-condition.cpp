class Solution {
public:
    int countSubarrays(vector<int>& a) {
        int n = a.size(), res = 0;
        for(int i = 0; i < n - 2; i++) {
            if((a[i] + a[i+2]) * 2 == a[i+1]) res++;
        }
        return res;
    }
};