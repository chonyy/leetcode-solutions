class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        # visited grid to avoid revisiting
        # minHeap with elevation, r, c
        # keep popping until meet bottom right

        dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]

        n = len(grid)
        visited = [[False] * n  for _ in range(n)]
        minHeap = [[grid[0][0], 0, 0]]

        while minHeap:
            height, r, c = heapq.heappop(minHeap)

            if r == n-1 and c == n-1:
                return height

            if visited[r][c]:
                continue

            visited[r][c] = True

            for dir in dirs:
                newR = r + dir[0]
                newC = c + dir[1]

                if (newR < 0 or newR >= n or newC < 0 or newC >= n):
                    continue

                newHeight = max(height, grid[newR][newC])
                heapq.heappush(minHeap, [newHeight, newR, newC])


        return -1
        