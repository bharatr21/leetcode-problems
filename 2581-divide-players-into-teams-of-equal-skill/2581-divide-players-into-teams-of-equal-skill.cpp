class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size(), vsum = 0;
        int div = n / 2;
        long long res = 0; 
        array<int, 1001> freq;
        unordered_set<int> seen;
        for(int i = 0; i < 1001; i++) freq[i] = 0;
        for(int el: skill) {
            vsum += el;
            freq[el]++;
        }
        if(vsum % div) return -1;
        if(n == 2) return skill[0] * skill[1];
        for(int i = 0; i < n; i++) {
            if(skill[i] <= vsum/div) {
                int comp = vsum/div - skill[i];
                if(seen.count(skill[i]) || seen.count(comp)) continue;
                if(freq[skill[i]] && freq[comp] && freq[skill[i]] == freq[comp]) {
                    int mult;
                    if(skill[i] == comp) mult = freq[comp] / 2;
                    else mult = freq[comp];
                    res += (long long)skill[i] * (long long)comp * mult;
                    seen.insert(skill[i]);
                    seen.insert(comp);
                } else return -1;
            }
        }
        return res;
    }
};