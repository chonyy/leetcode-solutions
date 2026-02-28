class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }

        int negative = x < 0 ? -1 : 1;
        x = abs(x);

        int res = 0;

        while (x) {
            if (res > INT_MAX / 10) {
                return 0;
            }
            res = res * 10;

            int digit = x % 10;
            res += digit;
            x = x / 10;
        }

        return res * negative;
    }
};