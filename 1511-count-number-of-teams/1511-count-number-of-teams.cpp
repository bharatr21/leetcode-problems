class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), i, j;
        vector<int> ratingsGreaterAfter(n, 0), ratingsLesserAfter(n, 0);
        int res = 0;
        for(i = 0; i < n; i++) {
            int base = rating[i];
            for(j = i+1; j < n; j++) {
                if(rating[j] < base) ratingsLesserAfter[i]++;
                else ratingsGreaterAfter[i]++;
            }
        }
        for(i = 0; i < n; i++) {
            for(j = i+1; j < n; j++) {
                if(rating[j] > rating[i]) res += ratingsGreaterAfter[j];
                else res += ratingsLesserAfter[j];
            }
        }
        return res;
    }
};