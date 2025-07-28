class Solution {
public:
    string processStr(string s) {
        string tmp;
        for(char ch: s) {
            if(ch == '*') {
                if(!tmp.empty()) tmp.pop_back();
            }
            else if(ch == '#') tmp += tmp;
            else if(ch == '%') reverse(tmp.begin(), tmp.end());
            else tmp += ch; 
        }
        return tmp;
    }
};