class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        stack = []

        n = len(heights)

        res = [0] * n
        stack.append(heights[-1])

        for i in reversed(range(n-1)):
            if stack[-1] > heights[i]:
                res[i] = 1; 
            else:
                popCount = 0
                while len(stack) > 0 and stack[-1] < heights[i]:
                    stack.pop()
                    popCount += 1
                if stack:
                    popCount += 1
                res[i] = popCount
            
            stack.append(heights[i])

        
        return res


# 10,6,8,5,11,9
# i

# res: 3 1 2 1 1 0

# stack: 10 11

# if stk.top() > cur
#     res = 1

# else

# pop all smaller
#     res = popCount + (stk.size() > 1)

# push onto stack