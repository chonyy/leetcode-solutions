class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        start = n-1
        end = 0
        cur = 0
        cur = gas[start] - cost[start]

        while end < start:
            if cur > 0:
                cur += gas[end] - cost[end]
                end += 1
            else:
                start -= 1
                cur += gas[start] - cost[start]

        return start if cur >= 0 else -1