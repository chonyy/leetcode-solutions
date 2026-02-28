class Solution {
public:
    int reverseBits(int n) {
        int res = 0;

        for (int i = 0; i < 32; i ++) {
            int mask = 1 << i;
            bool set = n & mask;

            // cout << set << endl;

            int resMask = 1 << (31 - i);
            if (set) {
                res = res | resMask;
            }
        }

        return res;
    }
};



// 00111
//  m

// 01110


// 11100