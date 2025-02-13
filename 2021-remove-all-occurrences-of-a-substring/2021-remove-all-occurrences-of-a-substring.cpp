class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int partSize = part.size();

        while(i < n) {
            s[j] = s[i];

            if(j >= partSize - 1 && s.substr(j - partSize + 1, partSize) == part) {
                j -= partSize;
            }

            j ++;
            i ++;
        }

        return s.substr(0, j);
    }
};