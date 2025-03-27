class Solution {
public:
    int transform(int& x, int& a, int& b, int& c) {
        return (a * x * x + b * x + c);
    }

    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> res;
        if(a < 0) {
            while(left <= right) {
                int lt = transform(nums[left], a, b, c);
                int rt = transform(nums[right], a, b, c);
                if(lt < rt) {
                    res.push_back(lt);
                    left++;
                } else {
                    res.push_back(rt);
                    right--;
                }
            }
        } else {
            while(left <= right) {
                int lt = transform(nums[left], a, b, c);
                int rt = transform(nums[right], a, b, c);
                if(lt > rt) {
                    res.push_back(lt);
                    left++;
                } else {
                    res.push_back(rt);
                    right--;
                }
            }
            reverse(res.begin(), res.end());
        }
        return res;
    }
};