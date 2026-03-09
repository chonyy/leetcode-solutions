class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        // loop through all asteroids
        // if positive, just add
        // if negative
                // if prev is empty or negative, just add
                // if prev is positivie, compare size
                //     if prev is bigger, skip current
                //     if prev is smaller, remove prev and add cur
                //     if prev is same, remove prev and skip

        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                res.push_back(asteroid);
                continue;
            }

            // remove all previous smaller positive asteroids
            while (!res.empty() && res.back() > 0 && res.back() < abs(asteroid)) {
                res.pop_back();
            }

            // collision
            if (res.empty()) {
                res.push_back(asteroid);
                continue;
            }

            // negative, just add
            if (res.back() < 0) {
                res.push_back(asteroid);
                continue;
            }

            // compare
            // either equal or larger
            if (res.back() == abs(asteroid)) { 
                res.pop_back();
            } 
        }
        
        return res;
    }
};