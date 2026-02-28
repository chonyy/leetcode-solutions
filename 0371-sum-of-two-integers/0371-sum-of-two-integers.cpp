class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (b & a) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};

// carry = b1 xor b2 xor b3
// remainder = (b1 xor b2 xor b3) == 0 && (b1 or b2 or b3) != 0

// 1 xor 1 xor 1 = 1
// 1 xor 0 xor 1 = 0
// 0 xor 0 xor 1 = 1
// 0 xor 0 xor 0 = 0

// b1  b2  carry =. carry remainder


// 0   0   0   =   0   0
// 0   0   1   =   0   1
// 0   1   0   =   0   1
// 0   1   1   =   1   0
// 1   0   0   =   0   1
// 1   0   1
// 1   1   0
// 1   1   1


// one bit set = 0 1
// two bit set = 1 0
// three bit set = 1 1

// | 
// &
// ^