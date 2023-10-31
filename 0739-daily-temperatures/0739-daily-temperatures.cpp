class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<pair<int, int>> st;
        int n = temps.size(), i;
        if(n == 1) return {0};
        vector<int> res(n, 0);
        st.push({temps[0], 0});
        for(i = 1; i < n; i++)
        {
            while(!st.empty() && st.top().first < temps[i]) {
                res[st.top().second] = (i - st.top().second);
                st.pop();
            }
            st.push({temps[i], i});
        }
        return res;
    }
};