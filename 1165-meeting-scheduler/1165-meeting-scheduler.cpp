class Solution {
public:
    bool hasOverlap(vector<int>& i1, vector<int>& i2) {
        return !((i1[0] > i2[1]) || (i2[0] > i1[1]));
    }
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<int> res;
        int m = slots1.size(), n = slots2.size(), i = 0, j = 0;
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        while(i < m && j < n) {
            vector<int> first = slots1[i], second = slots2[j];
            if(hasOverlap(first, second)) {
                if(min(first[1], second[1]) - max(first[0], second[0]) >= duration) {
                    int start = max(first[0], second[0]);
                    int end = min(first[1], second[1]);
                    return {start, min(end, start + duration)};
                }
                if(first[1] <= second[1]) i++;
                else j++;
            }
            else {
                if(first[1] <= second[0]) i++;
                else j++;
            }
        }
        return res;
    }
};