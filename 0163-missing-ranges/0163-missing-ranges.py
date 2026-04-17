class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        intls = []
        if n == 0:
            intls.append([lower, upper])
            return intls
        if lower < nums[0]:
            intls.append([lower, nums[0] - 1])
        for i in range(1, n):
            if nums[i] - 1 < nums[i-1] + 1: continue
            else:
                intls.append([nums[i-1] + 1, nums[i] - 1])
        if nums[n - 1] < upper:
            intls.append([nums[n - 1] + 1, upper])
        return intls