class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        MAX = float('inf')
        price = [MAX for _ in range(n)]

        # loop k + 1 times
        price[src] = 0

        for _ in range(k+1):
            tmp = price.copy()
            # for all edges, if start is not inf, check if we can reach dst with smaller price
            for start, end, cost in flights:
                if price[start] == MAX:
                    continue;

                tmp[end] = min(tmp[end], price[start] + cost)

            price = tmp


        return -1 if price[dst] == MAX else price[dst]
        