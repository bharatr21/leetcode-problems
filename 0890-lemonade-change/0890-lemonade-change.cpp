class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n5 = 0, n10 = 0, n20 = 0, n = bills.size();
        for(int i = 0; i < n; i++)
        {
            switch(bills[i]) {
                case 5: { n5++; break;}
                case 10: {
                    if(n5 <= 0) return false;
                    else {
                        n10++; 
                        n5--;
                    }
                    break;
                }
                case 20: {
                    if(n10 == 0 && n5 <= 2 || n5 <= 0) return false;
                    else {
                        n20++;
                        if(n10 > 0) {
                            n10--;
                            n5--;
                        }
                        else {
                            n5 -= 3;
                        }
                    }
                    break;
                }
            }
        }
        return true;
    }
};