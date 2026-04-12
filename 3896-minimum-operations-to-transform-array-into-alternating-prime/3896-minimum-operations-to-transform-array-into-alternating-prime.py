def prime():
    sieve = set()
    prime = [True] * 100003
    prime[0], prime[1] = False, False
    for i in range(2, 100003):
        if not prime[i]:
            continue
        else:
            sieve.add(i)
            for j in range(i * i, 100003, i):
                prime[j] = False

    return sieve

class Solution:
    def minOperations(self, nums: list[int]) -> int:
        n = len(nums)
        res = 0
        sieve = prime()
        for i in range(1, n, 2):
            if nums[i] in sieve:
                res += 2 if nums[i] == 2 else 1
        sl = sorted(list(sieve))
        for i in range(0, n, 2):
            if nums[i] not in sieve:
                idx = bisect.bisect_right(sl, nums[i])
                next_prime = sl[idx] if idx < len(sl) else 100003
                print(next_prime)
                res += next_prime - nums[i]
        return res