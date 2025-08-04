class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int st = 0, en = 0, d = 0, mx = -1;
        unordered_map<int, int> fre;
        while(en < n && st < n) {
            fre[fruits[en]]++;
            if(fre[fruits[en]] == 1) d++;
            while(d > 2) {
                fre[fruits[st]]--;
                if(fre[fruits[st]] == 0) {
                    d--;
                    fre.erase(fruits[st]);
                }
                st++;
            }
            mx = max(mx, en - st + 1);
            en++;
        }
        return mx;
    }
};