class Solution {
public:
    int lastRemaining(int n) {
        bool goRight = true;
        int head = 1;
        int step = 1;

        while (n > 1) {
            // move head
            if (goRight) {
                head += step;
            }
            else {
                // even: not chanage
                // odd: move step
                if (n % 2 == 1) {
                    head += step;
                }
            }

            // update
            n = n / 2;
            goRight = !goRight;
            step = step * 2;
        }

        return head;
    }
};

// 1 2 3
// 2

// 1 2 3 4
// 2 4
// 2

// 1 2 3 4 5
// 2 4
// 2

// 1 2 3 4 5 6
// 2 4 6
// 4

// 1 2 3 4 5 6 7
// 2 4 6
// 4

// 1 2 3 4 5 6 7 8
// 2 4 6 8
// 2 6
// 6


// 1 2 3 4 5 6 7 8 9 10
// 2 4 6 8 10
// 4 8
// 8