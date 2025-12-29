class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size(), rsum = 0, points = 0;
        for(int i = 0; i < k; i++) rsum += calories[i];
        for(int i = k; i < n; i++) {
            if(rsum < lower) points--;
            else if(rsum > upper) points++;
            rsum += (calories[i] - calories[i-k]);
        }
        if(rsum < lower) points--;
        else if(rsum > upper) points++;
        return points;
    }
};