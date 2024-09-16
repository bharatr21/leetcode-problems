class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for(string time: timePoints) {
            int hrs = stoi(time.substr(0, 2));
            int mins = stoi(time.substr(3, 2));
            int base = hrs * 60 + mins;
            times.push_back(base);
            times.push_back(1440 + base);
        }
        sort(times.begin(), times.end());
        int n = times.size(), res = 1440;
        for(int i = 1; i < n; i++) {
            res = min(res, times[i] - times[i-1]);

        }
        return res;
    }
};