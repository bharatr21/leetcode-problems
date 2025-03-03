class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        int k = 0, n0 = 0, res = n;
        for(int el: data) {
            if(el) k++;
        }
        for(int i = 0; i < k; i++) {
            if(!data[i]) n0++;
        }
        res = min(res, n0);
        for(int i = k; i < n; i++) {
            if(!data[i-k]) n0--;
            if(!data[i]) n0++;
            res = min(res, n0);
        }
        return res;
    }
};