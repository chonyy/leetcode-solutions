class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0;
        int leftMax = 0;

        for (char c : s) {
            if (c == '*') {
                leftMax ++;
                if (leftMin > 0) {
                    leftMin --;
                }
            }

            if (c == '(') {
                leftMax ++;
                leftMin ++;
            }

            if (c == ')') {
                leftMax --;

                if (leftMin > 0) {
                    leftMin --;
                }

                if (leftMax < 0) {
                    return false;
                }
            }
        }

        return leftMin == 0;
    }
};

// ( * ) )
//       i

// leftMax = 0
// leftMin = 0

// ( * )
//     i

// leftMax = 1
// leftMin = 0

// * (
// leftMax = 1
// leftMin = 1

// ( * * )
//       i

// leftMax = 2
// leftMin = 0