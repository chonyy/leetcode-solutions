class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        sIdx = 0

        if len(s) == 0:
            return True

        for tIdx in range(len(t)):
            if t[tIdx] == s[sIdx]:
                sIdx += 1

            if (sIdx == len(s)):
                break

        return sIdx == len(s)        