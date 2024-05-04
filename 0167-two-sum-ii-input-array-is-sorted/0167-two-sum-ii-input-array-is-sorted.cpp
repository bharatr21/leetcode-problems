class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n - 1;
        while(i < j && j >= 0 && i < n) {
            if(numbers[i] + numbers[j] == target) return {i+1, j+1};
            else if(numbers[i] + numbers[j] > target) j--;
            else i++;
        }
        return {-1, -1};
    }
};