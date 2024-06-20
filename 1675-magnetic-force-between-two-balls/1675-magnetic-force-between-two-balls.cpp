class Solution {
public:
    bool check(vector<int>& position, int mid, int m) {
        int n = position.size(), i;
        int val = position[0], ct = 1;
        for(i = 1; i < n; i++)
        {
            if(position[i] >= val + mid)
            {
                val = position[i];
                ct++;
            }
        }
        return (ct >= m);
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size(), i, res;
        int st = 1, en = (position[n-1] - position[0]) / (m - 1);
            while(st <= en) {
                int mid = st + (en - st) / 2;
                if(check(position, mid, m)) {
                    res = mid;
                    st = mid + 1;
                }
                else en = mid - 1;
            }
            return res;
        }
};