class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int n = chars.size();
        int insertIdx = 0;

        while (i < n) {
            chars[insertIdx] = chars[i];
            insertIdx ++;

            int j = i;
            while (j < n-1 && chars[j] == chars[j+1]) {
                j ++;
            }

            int len = j - i + 1;
            if (len > 1) {
                // append from i + 1
                append(chars, insertIdx, len);
            }

            // cout << j << endl;

            i = j + 1;
        }

        return insertIdx;
    }

    void append(vector<char>& chars, int& insertIdx, int len) {
        vector<char> digits;

        while (len) {
            digits.push_back(len % 10 + '0');
            len = len / 10;
        }
        reverse(digits.begin(), digits.end());

        for (char c : digits) {
            chars[insertIdx] = c;
            insertIdx ++;
        }
    }
};