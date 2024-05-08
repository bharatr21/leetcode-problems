class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(char ch: s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if(ch == ')')
                {
                    if(!st.empty() && st.top() == '(') st.pop();
                    else return false;
                }
                else if(ch == ']')
                {
                    if(!st.empty() && st.top() == '[') st.pop();
                    else return false;
                }
                else if(ch == '}')
                {
                    if(!st.empty() && st.top() == '{') st.pop();
                    else return false;
                }
            }
        }
        return st.empty();
    }
};