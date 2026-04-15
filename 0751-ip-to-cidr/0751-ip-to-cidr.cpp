class Solution {
public:
    long ipToLong(string& ip) {
        long res = 0;
        int num = 0;
        for (char c : ip) {
            if (c == '.') {
                res = (res << 8) + num;
                num = 0;
            } else {
                num = num * 10 + (c - '0');
            }
        }
        return (res << 8) + num;
    }

    string longToIp(long n) {
        return to_string((n >> 24) & 255) + "." +
               to_string((n >> 16) & 255) + "." +
               to_string((n >> 8) & 255) + "." +
               to_string(n & 255);
    }

    vector<string> ipToCIDR(string ip, int n) {
        // get lowest set bit 
        // try advance by bit, take min(n, 2^bit)
        // if 2^bit is smaller, n -= 2&bit
        // else try divide by 2 until it's smaller

        vector<string> res;
        long cur = ipToLong(ip);

        while (n) {
            long lowestBit = cur & -cur;
            if (lowestBit == 0) lowestBit = 1L << 31;

            // cout << "cur " << cur << endl;
            // cout << "lowest bit" << lowestBit << endl;

            while (lowestBit > n) {
                lowestBit >>= 1;
            }
            int bits = log2(lowestBit);

            res.push_back(longToIp(cur) + "/" + to_string(32 - bits));
            cur += lowestBit;
            n -= lowestBit;
        }

        return res;
    }
};