class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<int,vector<int>> count;
        count[0].push_back(-1);
        int res = 0;

        int zero = 0;
        int one = 0;
        for (char c : s) {
            zero += c == '0';
            one += c == '1';
        }

        int sum = 0;
        for (int i = 0; i < s.size(); i ++) {
            sum += s[i] == '1' ? 1 : -1;
            // cout << sum << endl;

            if (count.contains(sum)) {
                int len = i - count[sum][0];
                res = max(res, len);
            }

            if (count.contains(sum - 2)) {
                // cout << "check " << sum -2 << endl;
                // need zero
                for (int j : count[sum - 2]) {
                    int len = i - j;
                    int sum = 2;
                    int curOne = (len + sum) / 2;
                    int curZero = len - curOne;

                    if (curZero < zero) {
                        res = max(res, len);
                        // break;
                    }
                }
            }

            if (count.contains(sum + 2)) {
                // cout << "check " << sum + 2 << endl;
                // need one
                for (int j : count[sum + 2]) {
                    int len = i - j;
                    int sum = -2;
                    int curOne = (len + sum) / 2;
                    // cout << "len " << len << endl;

                    if (curOne < one) {
                        res = max(res, len);
                        // break;
                    }
                }
            }

            count[sum].push_back(i);
        }

        return res;
    }
};

// one + zero = len
// one - zero = sum

// one = len + sum / 2
// zero = len - one
