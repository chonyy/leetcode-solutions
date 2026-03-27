class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ""
        i = 0
        stop = False

        while True:
            for strIdx, s in enumerate(strs):
                if i >= len(s):
                    stop = True
                    break

                if strIdx == 0:
                    continue
                
                if s[i] != strs[strIdx-1][i]:
                    stop = True
                    break

            if stop:
                break


            res += strs[0][i]
            i += 1

        return res