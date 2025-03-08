class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int res = INT_MAX;
        int black = 0;

        int i = 0;
        int j = 0;

        while(j < n) {
            black += blocks[j] == 'B';

            if(j - i + 1 > k) {
                black -= blocks[i] == 'B';
                i ++;
            }

            res = min(res, k - black);
            j ++;
        }

        return res;
    }
};