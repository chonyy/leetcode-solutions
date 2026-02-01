class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> pairs;
        int n = position.size();

        for (int i = 0; i < n; i ++) {
            double time = (double)(target - position[i]) / speed[i];
            pairs.push_back({position[i], time});
        }
        sort(pairs.rbegin(), pairs.rend());

        int res = 0;
        double prevMax = 0;

        for(auto& p : pairs) {
            // cout << p.second << endl;
            if (res == 0) {
                res ++;
                prevMax = p.second;
                continue;
            }

            if (p.second > prevMax) {
                // cout << p.second << "larger than " << prevMax << endl;
                res ++;
                prevMax = p.second;
            }
        }

        return res;
    }
};

// 10,8,0,5,3
// 2,4,1,1,3
// 1,1,12,7,3

// 10,1: pos 10 takes 1 time to reach
// 8,1
// 5,7
// 3,3
// 0,12

// 1,7,13