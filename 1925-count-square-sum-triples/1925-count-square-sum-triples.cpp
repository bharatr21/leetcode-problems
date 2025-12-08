class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        double c = 0.0;
        for(int a = 1; a <= n; a++) {
            for(int b = 1; b <= n; b++) {
                c = sqrt(a * a + b * b);
                if(c == int(c) && c <= n) res++; 
            }
        }
        return res;
    }
};