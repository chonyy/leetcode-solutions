class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // minHeap
        // push all first element to minHeap
        // <value, listIdx, numIdx>
        int k = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        int maxNum = INT_MIN;
        for (int i = 0; i < k; i ++) {
            pq.push({nums[i][0], i, 0});
            maxNum = max(maxNum, nums[i][0]);
        }

        int minRange = maxNum - pq.top()[0];
        int resMin = pq.top()[0];
        int resMax = maxNum;

        // pop smallest from minHeap until end
        while (pq.size() == k) {
            auto& cur = pq.top();
            int val = cur[0];
            int listIdx = cur[1];
            int numIdx = cur[2];
            pq.pop();

            // compare minRange and update
            int range = maxNum - val;
            if (range < minRange) {
                minRange = range;
                resMin = val;
                resMax = maxNum;
            }

            // push new and update maxNum
            if (numIdx < nums[listIdx].size() - 1) {
                int newNum = nums[listIdx][numIdx + 1];
                maxNum = max(maxNum, newNum);
                pq.push({newNum, listIdx, numIdx + 1});
            }
        }

        return {resMin, resMax};
    }
};