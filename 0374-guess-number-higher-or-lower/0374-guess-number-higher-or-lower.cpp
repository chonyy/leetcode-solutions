/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int newGuess = guess(mid);

            if (newGuess == 0) {
                return mid;
            } else if (newGuess == -1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        // never trigger
        return -1;
    }
};