from collections import Counter

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        words1c = dict(Counter(s1.split()))
        words2c = dict(Counter(s2.split()))
        words1 = set(words1c.keys())
        words2 = set(words2c.keys())
        return [s for s in list(words1.difference(words2) | words2.difference(words1)) if words1c.get(s, 0) == 1 or words2c.get(s, 0) == 1]