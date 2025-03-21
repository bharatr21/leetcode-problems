class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        vector<int> tmp(sz, -1);
        int res = 0;
        for(int i = 0; i < sz; i++) {
            if(flowerbed[i] == 1 && tmp[i] == -1) {
                tmp[i] = 1;
                if(i >= 1) tmp[i-1] = 0;
                if(i < n - 1) tmp[i+1] = 0;
            }
        }
        for(int i = 0; i < sz; i++) {
            if(tmp[i] == -1) {
                if(i >= 1 && tmp[i-1] == 1) continue;
                if(i < n - 1 && tmp[i+1] == 1) continue;
                res++;
                tmp[i] = 1;
                if(i >= 1) tmp[i-1] = 0;
                if(i < n - 1) tmp[i+1] = 0;
            }
        }
        return (res >= n);
    }
};