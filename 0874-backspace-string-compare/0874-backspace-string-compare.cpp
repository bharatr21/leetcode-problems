class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string res, ret;
        stack<char> ss, st;
        for(char ch: s) {
            if(ch == '#' && !ss.empty()) ss.pop();
            else if(ch != '#') ss.push(ch); 
        }
        for(char ch: t) {
            if(ch == '#' && !st.empty()) st.pop();
            else if(ch != '#') st.push(ch); 
        }
        while(!ss.empty()) {
            res += ss.top();
            ss.pop();
        }
        while(!st.empty()) {
            ret += st.top();
            st.pop();
        }
        return (res == ret);
    }
};