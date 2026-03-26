class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        insertIdx = 0
        n = len(nums)

        i = 0
        while i < n:
            nums[insertIdx] = nums[i]
            insertIdx += 1

            j = i+1

            combo = 1
            while j < n and nums[j] == nums[j-1]:
                combo += 1
                if combo <= 2:
                    nums[insertIdx] = nums[j]
                    insertIdx += 1
                j += 1

            i = j

        return insertIdx


# 1,1,1,1,1,2,2,3
#   i
#   j
#   k

# combo = 1

# if combo <= 2, insert