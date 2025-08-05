class Solution:
    def simplifyPath(self, path: str) -> str:
        paths = path.split('/')
        res = []
        for path in paths:
            if path and path != '.':
                if path == '..':
                    if res: res.pop()
                else:
                    res.append(path)
        return '/' + '/'.join(res)