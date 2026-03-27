class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        n = len(s)
        res = 0
        foundWord = False

        i = n - 1

        while i >= 0:
            if s[i] == ' ':
                if foundWord:
                    break
                else:
                    i -= 1
                    continue

            res += 1
            foundWord = True
            i -= 1


        return res
            