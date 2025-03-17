class Solution {
public:
    int settle(int idx, vector<int>& debts) {
        int n = debts.size();
        while(idx < n && !debts[idx]) idx++;
        if(idx == n) return 0;
        int min_trans = 101;
        for(int nxt = idx + 1; nxt < n; nxt++) {
            if(!debts[nxt]) continue;
            //Settle debt idx -> nxt
            if(debts[idx] * debts[nxt] < 0) {
                debts[nxt] += debts[idx];
                min_trans = min(min_trans, 1 + settle(idx + 1, debts));
                debts[nxt] -= debts[idx]; //Trigger backtracking
            }
        }
        return min_trans;
    }
    int minTransfers(vector<vector<int>>& transactions) {
        int mx = -1;
        for(vector<int> v: transactions) {
            mx = max(mx, max(v[0], v[1]));
        }
        vector<int> amounts(mx+1, 0);
        vector<int> debts;
        for(vector<int> v: transactions) {
            amounts[v[0]] += v[2];
            amounts[v[1]] -= v[2];
        }
        for(int amt: amounts) {
            if(amt != 0) debts.push_back(amt);
        }
        int n = debts.size();
        for(int i=0; i < n; i++) cout << i << ' ' << debts[i] << endl;
        return settle(0, debts);
    }
};