class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> nge;
        stack<int> st;
        for(auto el: nums2) {
            while(!st.empty() && el > st.top()) {
                nge[st.top()] = el;
                st.pop();
            }
            st.push(el);
        }
        while(!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }
        for(auto el: nums1) {
            res.push_back(nge[el]);
        }
        return res;
    }
};