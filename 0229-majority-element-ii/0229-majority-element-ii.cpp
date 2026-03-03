class Solution {
public:

    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;

        for (int num : nums) {
            count[num] ++;

            if (count.size() >= 3) {
                unordered_map<int,int> newCount;
                for (auto& entry : count) {
                    entry.second --;

                    if (entry.second > 0) {
                        newCount[entry.first] = entry.second;
                    }
                }
                count = newCount;
            }
        }

        vector<int> res;
        for (auto& entry : count) {
            int freq = 0;
            for (int num : nums) {
                freq += num == entry.first;
            }

            if (freq > nums.size() / 3) {
                res.push_back(entry.first);
            }
        }

        return res;
    }
};


// 3 2 3 2 2 2 1 3 3
//         i

// res1 = 3
// count1 = 2

// res2 = 2
// count2 = 2
