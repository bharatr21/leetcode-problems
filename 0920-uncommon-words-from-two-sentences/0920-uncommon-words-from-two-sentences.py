from collections import Counter

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        words1c = dict(Counter(s1.split()))
        words2c = dict(Counter(s2.split()))
        return [s for s in list(set(words1c.keys()).difference(set(words2c.keys())) | set(words2c.keys()).difference(set(words1c.keys()))) if words1c.get(s, 0) == 1 or words2c.get(s, 0) == 1]