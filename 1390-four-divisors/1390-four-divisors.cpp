class Solution {
public:
    vector<int> checkFourDivisors(int n) {
        vector<int> divi, empty;
        divi.push_back(1);
        divi.push_back(n);
        for(int i = 2; i * i <= n && divi.size() <= 4; i++) {
            if(n % i == 0) {
                divi.push_back(i);
                if(i * i != n) divi.push_back(n / i);
            }
        }
        return ((divi.size() == 4) ? divi : empty);
    }

    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(int el: nums) {
            vector<int> divi = checkFourDivisors(el);
            // cout << "Divisors for: " << el << endl;
            // for(int ele: divi) cout << ele << ' ';
            // cout << endl;
            if(!divi.empty()) res += accumulate(divi.begin(), divi.end(), 0);
        }
        return res;
    }
};