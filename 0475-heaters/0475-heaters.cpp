class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int m = heaters.size(), n = houses.size(), mx = 0;
        for(int i = 0; i < n; i++) {
            auto ub = upper_bound(heaters.begin(), heaters.end(), houses[i]);
            int tmp = 1e9 + 1; 
            if(ub != heaters.end()) tmp = abs(houses[i] - *ub);
            if(ub != heaters.begin()) tmp = min(tmp, abs(houses[i] - *prev(ub)));
            mx = max(mx, tmp);
        }
        return mx;
    }
};