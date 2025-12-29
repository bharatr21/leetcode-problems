class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size(), rsum = 0, points = 0;
        for(int i = 0; i < k; i++) rsum += calories[i];
        if(rsum < lower) points--;
        else if(rsum > upper) points++;
        for(int i = 0; i < n - k; i++) {
            rsum += (calories[i+k] - calories[i]);
            if(rsum < lower) points--;
            else if(rsum > upper) points++;
        }
        return points;
    }
};