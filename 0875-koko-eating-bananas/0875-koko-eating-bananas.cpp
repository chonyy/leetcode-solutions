class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxB = 0;

        for (int p : piles) {
            maxB = max(maxB, p);
        }

        int l = 1;
        int r = maxB + 1;
        int ans = INT_MAX;

        while (l < r) {
            int speed = l + (r - l) / 2;
            int hours = getEatHours(piles, speed);
            // cout << speed << " " << hours << endl;

            if (hours <= h) {
                ans = min(ans, speed);
                r = speed;
            }
            else {
                l = speed + 1;
            }
        }

        return ans;
    }

    int getEatHours(vector<int>& piles, int speed) {
        int hours = 0;

        for (int p : piles) {
            hours += p / speed;
            if (p % speed) {
                hours ++;
            }
        }

        return hours;
    }
};