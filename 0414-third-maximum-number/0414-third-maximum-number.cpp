class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long mx = LONG_MIN, smx = LONG_MIN, tmx = LONG_MIN;
        for(int el: nums) {
            if(mx < el) {
                tmx = smx;
                smx = mx;
                mx = el;
            } else if(smx < el && el < mx) {
                tmx = smx;
                smx = el;
            } else if(tmx < el && el < smx) {
                tmx = el;
            }
        }
        return (int)((tmx == LONG_MIN) ? mx : tmx);
    }
};