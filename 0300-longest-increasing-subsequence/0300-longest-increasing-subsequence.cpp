class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;

        for (int num : nums) {
            auto it = lower_bound(temp.begin(), temp.end(), num);

            if (it == temp.end()) {
                temp.push_back(num);
            }
            else {
                int idx = it - temp.begin();
                temp[idx] = num;
            }
        }

        return temp.size();
    }
};

// 10,9,2,5,3,7,101,18
//              i

// temp: 2, 3, 7