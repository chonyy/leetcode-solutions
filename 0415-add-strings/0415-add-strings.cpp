class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        string res = "";

        int i = m - 1;
        int j = n - 1;

        int carry = 0;

        while (i >= 0 || j >= 0) {
            int digit1 = i < 0 ? 0 : num1[i] - '0';
            int digit2 = j < 0 ? 0 : num2[j] - '0';

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            res += sum + '0';

            if (i >= 0) {
                i --;
            }
            if (j >= 0) {
                j --;
            }
        }

        if (carry) {
            res += '1';
        }

        reverse(res.begin(), res.end());

        return res;
    }
};