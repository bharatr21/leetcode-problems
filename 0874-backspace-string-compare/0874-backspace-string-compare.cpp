class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string rs, rt;
        stack<char> st1, st2;
        for(char ch: s)
        {
            if(!st1.empty() && ch == '#') st1.pop();
            else if(ch != '#') st1.push(ch);
        }
        for(char ch: t)
        {
            if(!st2.empty() && ch == '#') st2.pop();
            else if(ch != '#') st2.push(ch);
        }
        while(!st1.empty())
        {
            rs += st1.top();
            st1.pop();
        }
        while(!st2.empty())
        {
            rt += st2.top();
            st2.pop();
        }
        return (rs == rt);

    }
};