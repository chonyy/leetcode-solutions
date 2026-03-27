class Solution:
    def canJump(self, nums: List[int]) -> bool:
        reach = 0
        n = len(nums)

        for i in range(n):
            if i > reach:
                return False
            reach = max(reach, i + nums[i])


        return True