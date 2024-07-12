class Solution {
public:
    pair<int, string> removeab(string& s, int x) {
        string st;
        int tot = 0;
        for(char c: s) {
            if(st.size() && st.back() == 'a' && c == 'b') {
                st.pop_back();
                tot += x;
            }
            else st.push_back(c);
        }
        return {tot, st}; 
    }

    pair<int, string> removeba(string& s, int y) {
        string st;
        int tot = 0;
        for(char c: s) {
            if(st.size() && st.back() == 'b' && c == 'a') {
                st.pop_back();
                tot += y;
            }
            else st.push_back(c);
        }
        return {tot, st}; 
    }

    int maximumGain(string s, int x, int y) {
        int res = 0;
        if(x > y) {
            auto [tot, temp] = removeab(s, x);
            res += tot;
            res += removeba(temp, y).first;
        }
        else {
            auto [tot, temp] = removeba(s, y);
            res += tot;
            res += removeab(temp, x).first;
        }
        return res;
    }
};