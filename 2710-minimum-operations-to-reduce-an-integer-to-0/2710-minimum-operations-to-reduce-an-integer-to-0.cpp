class Solution {
public:
    int minOperations(int n) {
        int tmp = n, ct = 0;
        vector<int> pow2;
        for(int i = 1; i <= 100000; i <<= 1) {
            pow2.push_back(i);            
        }
        while(tmp) {
            int near = *min_element(pow2.begin(), pow2.end(), 
            [&tmp](int a, int b) {
                return abs(tmp - a) < abs(tmp - b);
            });
            tmp = abs(tmp - near);
            ct++;
        }
        return ct;
    }
};