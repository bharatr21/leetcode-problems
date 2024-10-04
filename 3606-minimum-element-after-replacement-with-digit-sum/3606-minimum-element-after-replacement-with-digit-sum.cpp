class Solution {
public:
    int sumd(int n) {
        int temp = n, res = 0;
        if(temp >= 1 && temp <= 9) return temp;
        while(temp) {
            res += (temp % 10);
            temp /= 10;
        }
        return res;
    }
    int minElement(vector<int>& nums) {
        vector<int> res = nums;
        int n = res.size();
        for(int i = 0; i < n; i++) {
            res[i] = sumd(res[i]);
        }
        return *min_element(res.begin(), res.end());
    }
};