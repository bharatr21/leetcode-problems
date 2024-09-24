class Solution {
public:
    void prefixes(int n, unordered_set<int>& s) {
        int tmp = n;
        while(tmp) {
            s.insert(tmp);
            tmp /= 10;
        }
    }

    int len(int n) {
        int tmp = n, ct = 0;
        while(tmp) {
            ct++;
            tmp /= 10;
        }
        return ct;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s1, s2;
        sort(arr2.begin(), arr2.end(), greater<int>());
        for(int el: arr1) {
            prefixes(el, s1);
        }
        for(int el: arr2) {
            prefixes(el, s2);
        }
        vector<int> v2(s2.begin(), s2.end());
        sort(v2.begin(), v2.end(), greater<int>());
        for(int el: v2) {
            if(s1.count(el)) return len(el);
        }
        return 0;
    }
};