class Solution:
    def jump(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        maxReach = 0
        reach = 0

        for i in range(n):
            if i > reach:
                res += 1
                reach = maxReach
            maxReach = max(maxReach, i + nums[i])

        return res
        