class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int i = 0;
        int n = s.size();

        while (i < n && s[i] == ' ') {
            i ++;
        }

        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }

        int sum = 0;

        // skip zeros
        while (i < n && s[i] == '0') {
            i ++;
        }

        while (i < n) {
            if (!isdigit(s[i])) {
                break;
            }

            // Check BEFORE multiplying
            int digit = s[i] - '0';
            if (sum > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            sum = sum * 10;
            sum += digit;

            i ++;
        }

        return sum * sign;
    }
};