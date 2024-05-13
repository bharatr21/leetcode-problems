class Solution {
public:
    bool check(vector<int>& piles, int k, int h) {
        int res = 0;
        for(int el: piles) res += ceil((1.0 * el) / k);
        return (res <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(check(piles, mid, h)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};