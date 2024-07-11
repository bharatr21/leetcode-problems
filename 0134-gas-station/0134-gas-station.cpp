class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), i, st = 0, tot = 0, fuel = 0;
        for(i = 0; i < n; i++)
        {
            tot += (gas[i] - cost[i]);
            fuel += (gas[i] - cost[i]);

            if(fuel < 0) {
                st = i + 1;
                fuel = 0;
            }
        }
        return ((tot >= 0) ? st : -1); 
    }
};