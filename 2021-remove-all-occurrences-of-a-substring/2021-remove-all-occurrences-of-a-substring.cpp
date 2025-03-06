class Solution {
public:
    bool check(stack<char> stk, string part, int partLen) {
        stack<char> tmp;
        for(int i = partLen - 1; i >= 0; i--) {
            if(stk.top() == part[i]) {
                tmp.push(stk.top());
                stk.pop();
            }
            else return false;
        }
        return (tmp.size() == partLen);
    }
    string removeOccurrences(string s, string part) {
        stack<char> stk;
        int n = s.size(), partLen = part.size();
        string res;
        for(int i = 0; i < n; i++) {
            stk.push(s[i]);
            while(stk.size() >= partLen && check(stk, part, partLen)) {
                for(int i = 0; i < partLen; i++) stk.pop();
            }
        }
        while(!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};