class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int div = n / 2;
        long long res = 0; 
        int vsum = accumulate(skill.begin(), skill.end(), 0);
        if(vsum % div) return -1;
        if(n == 2) return skill[0] * skill[1];
        sort(skill.begin(), skill.end());
        for(int i = 0; i < div; i++) {
            if(skill[i] + skill[n-i-1] != vsum / div) return -1;
            res += skill[i] * skill[n-i-1];
        }
        return res;
    }
};