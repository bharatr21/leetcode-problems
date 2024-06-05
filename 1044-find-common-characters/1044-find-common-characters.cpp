class Solution {
public:
    string lcs(string w1, string w2) {
        string res;
        int m = w1.size(), n = w2.size(), i = 0, j = 0;
        while(i < m && j < n) {
            if(w1[i] == w2[j]) {
                res += w1[i];
                i++;
                j++;
            }
            else if(w1[i] < w2[j]) i++;
            else j++;
        }
        return res;
    }

    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        string ires;
        int n = words.size(), i;
        if(n == 1) return format(words[0]);
        for(i = 0; i < n; i++)
            sort(words[i].begin(), words[i].end());
        for(i = 0; i < n; i++)
            cout << words[i] << " ";
        ires = lcs(words[0], words[1]);
        for(i = 2; i < n; i++) {
            ires = lcs(ires, words[i]);
        }
        res = format(ires);
        return res;
    }

    vector<string> format(string ans) {
        vector<string> res;
        for(char ch: ans) {
            string tmp(1, ch);
            res.push_back(tmp);
        }
        return res;
    }
};