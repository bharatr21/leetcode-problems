class Solution {
public:
    bool check(vector<int>& ribbons, int len, int k) {
        int cnt = 0;
        for(int el: ribbons) {
            cnt += (el / len);
        }
        return (cnt >= k);
    }

    int maxLength(vector<int>& ribbons, int k) {
        int lb = 0, ub = *max_element(ribbons.begin(), ribbons.end());
        while(lb < ub) {
            int mid = (lb + ub + 1) / 2; // Crucial to prevent infinite loops here!
            if(check(ribbons, mid, k)) {
                lb = mid;
            }
            else ub = mid - 1;
        }
        return lb;
    }
};