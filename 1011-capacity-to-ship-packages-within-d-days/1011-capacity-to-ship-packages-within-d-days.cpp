class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxWeight = 0;

        for (int w : weights) {
            sum += w;
            maxWeight = max(maxWeight, w);
        }

        int l = maxWeight;
        int r = sum;

        while (l < r) {
            int mid = l + (r - l) / 2;
            
            // cout << mid << endl;
            if (canShip(mid, days, weights)) {
                r  = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }

    bool canShip(int capacity, int days, vector<int>& weights) {
        int dayCount = 1;
        int cur = capacity;

        for (int w : weights) {
            if (cur < w) {
                dayCount ++;
                cur = capacity;
            }

            cur -= w;
            // cout << cur << " ";
        }
        cout << endl;

        // cout << "day " << dayCount << endl;
        return dayCount <= days;
    }
};


// 1,2,3,4,5,6,7,8,9,10
        //  1 