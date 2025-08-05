class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), ct = 0;
        vector<bool> fill(n, false);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!fill[j] && baskets[j] >= fruits[i]) {
                    fill[j] = true;
                    break;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(!fill[i]) ct++;
        }
        return ct;
    }
};