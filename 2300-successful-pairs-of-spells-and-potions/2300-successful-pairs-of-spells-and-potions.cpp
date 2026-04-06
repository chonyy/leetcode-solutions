class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        
        for (int spell : spells) {
            long long need = ceil((double)success / spell);
            auto it = lower_bound(potions.begin(), potions.end(), need);
            int idx = it - potions.begin();
            res.push_back(potions.size() - idx);
        }

        return res;
    }
};

// 1,2,3,4,5

// 1 