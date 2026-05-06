/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    
    char temp[4];
    int buffIdx = 0;
    int buffSize = 0;

    int read(char *buf, int n) {
        int copied = 0;

        while (copied < n) {
            if (buffIdx < buffSize) {
                buf[copied] = temp[buffIdx];
                copied ++;
                buffIdx ++;
            }
            else if (n - copied >= 4) {
                int read = read4(buf + copied);
                if (read == 0) {
                    break;
                }
                
                copied += 4;
            }
            else if (buffIdx == buffSize) {
                int read = read4(temp);
                if (read == 0) {
                    break;
                }

                buffIdx = 0;
                buffSize = read;
            }
        }

        return copied;
    }
};