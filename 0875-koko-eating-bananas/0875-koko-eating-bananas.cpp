class Solution {
public:
    bool eat(int speed, vector<int>& piles, int remain) {
        
        for(int pile : piles) {
            double exactTime = (double)pile / speed;
            int timesNeeded = ceil(exactTime);
            remain -= timesNeeded;
        }
        
        return remain >= 0;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;
        for(int pile : piles) {
            maxPile = max(maxPile, pile);
        }
        
        // Start the binary search
        int l = 1;
        int r = maxPile+1;
        
        while(l < r) {
            int mid = l + (r-l) / 2;
            if(eat(mid, piles, h)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};
