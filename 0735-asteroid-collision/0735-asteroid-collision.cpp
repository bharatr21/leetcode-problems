class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int a: asteroids) {
            int flag = 1;
            while(!st.empty() && (st.top() > 0 && a < 0)) {
                int pt = abs(st.top()), nt = abs(a);
                if(pt < nt) { st.pop(); continue;}
                else if(pt == nt) st.pop();
                flag = 0;
                break;
            }
            if(flag) st.push(a);
        }
        vector<int> res(st.size());
        for(int i = res.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};