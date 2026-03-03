class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSumCount;
        int prefixSum = 0;
        int res = 0;
        prefixSumCount[0] = 1;

        // loop through nums
        // keep track of prefixSum
        // add prefixSum to hashMap
        // res += k - prefixSumCount[num];

        for (int num : nums) {
            prefixSum += num;

            int need = prefixSum - k;
            res += prefixSumCount[need];

            prefixSumCount[prefixSum] ++;

        }

        return res;
    }
};

// 1,2,3
//     i

// res = 2

// 0: 1
// 1: 1
// 3: 1
// 6: 1