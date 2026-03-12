class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0]*n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.rank[pa] < self.rank[pb]:
            pa, pb = pb, pa
        self.parent[pb] = pa
        if self.rank[pa] == self.rank[pb]:
            self.rank[pa] += 1
        return True


class Solution:
    def maxStability(self, n, edges, k):

        def can(x):
            dsu = DSU(n)
            upgrades = 0
            used = 0

            optional = []

            for u, v, s, must in edges:
                if must == 1:
                    if s < x:
                        return False
                    if not dsu.union(u, v):
                        return False
                    used += 1
                else:
                    optional.append((u, v, s))

            # IMPORTANT FIX
            if used == n - 1:
                return True

            zero = []
            one = []

            for u, v, s in optional:
                if s >= x:
                    zero.append((u, v))
                elif s * 2 >= x:
                    one.append((u, v))

            for u, v in zero:
                if dsu.union(u, v):
                    used += 1
                if used == n - 1:
                    return True

            for u, v in one:
                if upgrades == k:
                    break
                if dsu.union(u, v):
                    upgrades += 1
                    used += 1
                if used == n - 1:
                    return True

            return False

        left = 1
        right = max(s for _,_,s,_ in edges) * 2
        ans = -1

        while left <= right:
            mid = (left + right) // 2

            if can(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1

        return ans