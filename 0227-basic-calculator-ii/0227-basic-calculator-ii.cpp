class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int res = 0;
        stack<int> st;
        int cur = 0;
        char op = '+';
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if(isdigit(ch)) {
                cur = cur * 10 + (ch - '0');
            } 
            if(!isdigit(ch) && !isspace(ch) || i == n - 1) {
                if(op == '-') {
                    st.push(-cur);
                } 
                if(op == '+'){
                    st.push(cur);
                }
                if(op == '*'){
                    int num = st.top();
                    st.pop();
                    st.push(num * cur);
                }
                if(op == '/') {
                    int num = st.top();
                    st.pop();
                    st.push(num / cur);
                }
                op = ch;
                cur = 0;
            }
        }
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};