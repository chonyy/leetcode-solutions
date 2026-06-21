class Solution {
public:
    int maxx = 100001;

    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> bucket(maxx);

        for (int cost : costs) {
            bucket[cost] ++;
        }

        int res = 0;

        for (int i = 0; i < maxx; i ++) {
            if (bucket[i] == 0) {
                continue;
            }
            
            while (coins >= i && bucket[i]) {
                res ++;
                coins -= i;
                bucket[i] --;
            }

            if (bucket[i] > 0 && coins > 0) {
                break;
            }
        }

        return res;
    }
};