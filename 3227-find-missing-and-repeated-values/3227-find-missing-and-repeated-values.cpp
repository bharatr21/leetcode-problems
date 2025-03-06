class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> fre(n * n + 1, 0);
        int a, b;
        for(auto& el: grid) {
            for(auto& c: el) {
                fre[c]++;
            }
        }
        for(int i = 1; i <= n * n; i++) {
            if(fre[i] == 2) a = i;
            else if(fre[i] == 0) b = i;
        }
        return {a, b};
    }
};