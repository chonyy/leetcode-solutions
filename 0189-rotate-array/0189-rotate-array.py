class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)
        nums.reverse()
        self.reverse(nums, 0, k-1)
        self.reverse(nums, k, len(nums) - 1)

    def reverse(self, nums:List[int], start, end):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1
        

# 1,2,3,4,5,6,7


# 5,6,7,1,2,3,4