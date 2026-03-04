class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> bucket(limit + 1, 0);

        for (int p : people) {
            bucket[p] ++;
        }

        int l = 0;
        int r = limit;
        int boats = 0;

        while (l <= r && bucket[l] == 0) {
            l ++;
        }

        while (l <= r && bucket[r] == 0) {
            r --;
        }

        while (l <= r) {
            bucket[r] --;
            int remain = limit - r;

            if (bucket[r] == 0) {
                r --;
            }

            if (bucket[l] > 0 && l <= remain) {
                bucket[l] --;
                if(bucket[l] == 0) {
                    l ++;
                }
            }

            while (l <= r && bucket[l] == 0) {
                l ++;
            }

            while (l <= r && bucket[r] == 0) {
                r --;
            }

            boats ++;
        }

        return boats;
    }
};