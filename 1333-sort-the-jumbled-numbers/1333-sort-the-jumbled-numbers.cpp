class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
        return ((p1.first == p2.first) ? (p1.second < p2.second): (p1.first < p2.first));
    }
    int map(vector<int>& mapping, int num) {
        int res = 0, place = 1;
        do
        {
            int d = mapping[num % 10];
            num = num / 10;
            res += place * d;
            place *= 10;
        } while(num);
        return res;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> vp;
        vector<int> res;
        int n = nums.size(), i;
        for(i = 0; i < n; i++) {
            vp.push_back({map(mapping, nums[i]), i});
        }
        sort(vp.begin(), vp.end(), cmp);
        for(auto el: vp) cout << el.first << ":" << el.second << endl;
        for(auto u: vp) {
            res.push_back(nums[u.second]);
        }
        return res;
    }
};