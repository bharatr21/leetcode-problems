class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int mx = *max_element(damage.begin(), damage.end());
        int mn = min(mx, armor);
        return accumulate(damage.begin(), damage.end(), -mn * 1LL) + 1;
    }
};