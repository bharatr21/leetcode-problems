class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        adj = defaultdict(list)
        vis = set()
        res = 0
        q = deque()
        for i in range(len(informTime)):
            if i != headID:
                adj[manager[i]].append((i, informTime[manager[i]]))
        q.append((headID, 0)) # push()
        while q and len(vis) < n:
            mgr, cur_time = q.popleft()
            vis.add(mgr)
            res = max(res, cur_time)
            for emp, inform_time in adj[mgr]:
                if emp not in vis:
                    q.append((emp, cur_time + inform_time))
        return res

