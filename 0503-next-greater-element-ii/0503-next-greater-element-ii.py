class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        st = []
        nge = [-1] * n
        for i in range(2 * n):
            while st and st[-1][1] < nums[i % n]:
                idx, el = st.pop()
                nge[idx] = nums[i % n]
            st.append((i % n, nums[i % n]))
        return nge