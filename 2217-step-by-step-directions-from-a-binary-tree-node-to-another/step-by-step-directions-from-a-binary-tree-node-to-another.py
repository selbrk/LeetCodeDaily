# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.adj = defaultdict(list)
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        self.dfs(root)
        n = len(self.adj)
        ans = ""
        q = deque()
        vis = [False] * (n + 1)
        drs = ["" for _ in range(n + 1)]
        q.append(startValue)
        vis[startValue] = True
        while q:
            node = q.popleft()
            if node == destValue:
                break
            for adj, dr in self.adj[node]:
                if vis[adj]: continue
                if dr == 'L' or dr == 'R': drs[adj] = dr
                else:
                    for nd2, dr2 in self.adj[adj]:
                        if nd2 != node: continue
                        if dr2 == 'L':
                            drs[adj] = 'UR'
                        else:
                            drs[adj] = 'UL'
                vis[adj] = True
                q.append(adj)
        
        cur_node = destValue
        prev_node = None

        while cur_node != startValue:
            print(cur_node)
            ans += drs[cur_node][0]
            if drs[cur_node] == 'L' or drs[cur_node] == 'R':
                for node, dr in self.adj[cur_node]:
                    if dr == 'U':
                        cur_node = node
                        break
            else:
                for node, dr in self.adj[cur_node]:
                    if drs[cur_node] == 'UL' and dr == 'R':
                        cur_node = node
                        break
                    elif drs[cur_node] == 'UR' and dr == 'L':
                        cur_node = node
                        break

        print(drs)
        return ans[::-1]

    def dfs(self, root):
        if root.right:
            self.adj[root.val].append((root.right.val, 'R'))
            self.adj[root.right.val].append((root.val, 'U'))
            self.dfs(root.right)
        if root.left:
            self.adj[root.val].append((root.left.val, 'L'))
            self.adj[root.left.val].append((root.val, 'U'))
            self.dfs(root.left)
        




        