class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int m = heaters.size(), n = houses.size(), mx = 0;
        for(int& house: houses) {
            auto ub = upper_bound(heaters.begin(), heaters.end(), house);
            int tmp = 1e9 + 1; 
            if(ub != heaters.end()) tmp = abs(house - *ub);
            if(ub != heaters.begin()) tmp = min(tmp, abs(house - *prev(ub)));
            mx = max(mx, tmp);
        }
        return mx;
    }
};