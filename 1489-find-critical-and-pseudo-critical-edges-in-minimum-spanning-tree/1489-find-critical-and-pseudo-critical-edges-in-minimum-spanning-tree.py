class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [1 for _ in range(n)]

    def find(self, node):
        if self.parent[node] == node:
            return node
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def unionNode(self, n1, n2):
        p1 = self.find(n1)
        p2 = self.find(n2)

        if p1 == p2:
            return False

        r1 = self.rank[p1]
        r2 = self.rank[p2]

        if r1 >= r2:
            self.parent[p2] = p1
            self.rank[p1] += self.rank[p2]
        else:
            self.parent[p1] = p2
            self.rank[p2] += self.rank[p1]

        return True

        

class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        # append idx to edges
        for i, e in enumerate(edges):
            e.append(i)

        # sort edges
        edges.sort(key = lambda e : e[2])

        # find minWeight with MST
        minWeight = self.getWeight(n, edges)

        # loop through edges, try remove one. If weight > minWeight, it's critical
        # force adding edge, if weight == minWeight, it's pseudo

        critical = []
        pseudo = []

        for n1, n2, testW, i in edges:
            uf = UnionFind(n)
            weight = 0

            # try remove
            for start, end, w, j, in edges:
                if i == j:
                    continue

                if (uf.unionNode(start, end)):
                    weight += w

            if max(uf.rank) != n or weight > minWeight: # Got smaller weight or can't get MST at all
                critical.append(i)
                continue

            # try force adding
            uf = UnionFind(n)
            uf.unionNode(n1, n2)
            weight = testW

            # try remove
            for start, end, w, idx, in edges:
                if (uf.unionNode(start, end)):
                    weight += w

            if weight == minWeight:
                pseudo.append(i)

        return [critical, pseudo]


    def getWeight(self, n, edges):
        uf = UnionFind(n)
        res = 0

        for start, end, weight, idx, in edges:
            if (uf.unionNode(start, end)):
                res += weight

        return res