class Solution:
    def convert(self, s: str, numRows: int) -> str:
        res = ""

        if numRows == 1:
            return s

        for r in range(numRows):
            gap = (numRows - 1) * 2
            for i in range(r, len(s), gap):
                res += s[i]
                if r != 0 and r != numRows - 1:
                    extraIdx = i + gap - (r * 2)
                    # print("Extra", extraIdx)
                    if extraIdx < len(s):
                        res += s[extraIdx] 

        return res


# P     I    N
# A   L S  I G
# Y A   H R
# P     I

# P A Y P A L I S H I R I N G
#     i

# intput = PAYPALISHIRING
#                    i       

# expected = PAHNAPLSIIGYIR

# output = PAHNAPLS


# 2 * numRows - 2

# numRows = 3
# gap = 4

# numRows = 2
# gap = 2

# from 0 to gap
#     diff = gap
#     while diff > 0:
#         from 0 to n with diff change:

#         diff -= 2


# input = PAYPALISHIRING
#                  i

# numRows = 4
# gap = 6

# expected = PINALSIGYAHRPI

# output = PINAL