class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn = 0, runSum = 0;
        for(int el: nums) {
            runSum = runSum + el;
            mn = min(mn, runSum);
        }
        return (-mn + 1);
    }
};