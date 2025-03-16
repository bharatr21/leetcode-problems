class Solution {
public:
    bool check(vector<int>& ranks, int cars, long long time) {
        long long num_repaired = 0;
        for(auto el: ranks) {
            num_repaired += sqrt(1.0 * time/(long long)el);
        }
        return (num_repaired >= cars);
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        int minrank = *min_element(ranks.begin(), ranks.end());
        int maxrank = *max_element(ranks.begin(), ranks.end());
        long long left = 1, right = 1LL * minrank * cars * cars;
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(check(ranks, cars, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};