class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        int move = (numRows - 1) * 2;
        string res = "";

        if (move <= 0) {
            return s;
        }

        for (int i = 0; i < numRows; i ++) {
            int j = i;
            int shift = (numRows - 1 - i) * 2;
            while (j < n) {
                res.push_back(s[j]);
                // if in middle, also add shift
                if (i != 0 && i != numRows-1) {
                    if (j + shift < n) {
                        res.push_back(s[j + shift]);
                    }
                }
                j += move;
            }
        }

        return res;
    }
};

// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// move = 6
// rows = 4
// move = (rows - 1) * 2

// if in middle
// shift rowCount
// then move

// P   A   H   N
// A P L S I I G
// Y   I   R