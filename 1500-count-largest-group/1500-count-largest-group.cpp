class Solution {
public:
    int sumd(int n) {
        int tmp = n, res = 0;
        while(tmp) {
            res += (tmp % 10);
            tmp /= 10;
        }
        return res;
    }

    int countLargestGroup(int n) {
        vector<int> hash(37, 0);
        int mx = 0, res = 0;
        for(int i = 1; i <= n; i++) {
            hash[sumd(i)]++;
        }
        for(int i = 1; i <= 36; i++) {
            if(mx < hash[i]) {
                mx = hash[i];
                res = 1;
            }
            else if(mx == hash[i]) {
                res++;
            }
        }
        return res;
    }
};