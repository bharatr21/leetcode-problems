class Solution:
    def killProcess(self, pid: List[int], ppid: List[int], kill: int) -> List[int]:
        n = len(pid)
        children = defaultdict(list)
        res = []
        for i in range(n):
            children[ppid[i]].append(pid[i])

        q = deque()
        q.append(kill)
        while q:
            pid = q.popleft()
            res.append(pid)
            if pid in children:
                for child in children[pid]:
                    q.append(child)
        
        return res