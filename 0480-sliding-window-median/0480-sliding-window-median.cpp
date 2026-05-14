class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // sliding window with size
        // multiset maxHeap
        // multiset minHeap
        multiset<int, greater<>> maxHeap;
        multiset<int> minHeap;

        int l = 0;
        int r = 0;
        int n = nums.size();

        vector<double> res;

        while (r < n) {
            // cout << r << endl;
            // when out of bound, try remove from minHeap and maxHeap
            if (r - l == k) {
                int toDelete = nums[l];
                if (minHeap.contains(toDelete)) {
                    minHeap.erase(minHeap.find(toDelete));
                }
                else if (maxHeap.contains(toDelete)) {
                    maxHeap.erase(maxHeap.find(toDelete));
                    maxHeap.insert(*minHeap.begin());
                    minHeap.erase(minHeap.begin());
                }
                l ++;
            }

            // when maxHeap.size > k / 2, move element to minHeap
            // if maxHeap.top() > minHeap.top(), swap
            // if odd: ans = minHeap.top();
            // if event: avg of minHeap.top() and maxHeap.top();
            // cout << "inserting " << endl;
            maxHeap.insert(nums[r]);

            if (maxHeap.size() > k / 2) {
                minHeap.insert(*maxHeap.begin());
                maxHeap.erase(maxHeap.begin());
            }

            // cout << "comparing " << endl;
            if (!maxHeap.empty() && !minHeap.empty() && *maxHeap.begin() > *minHeap.begin()) {
                // cout << "swapping " << endl;
                int minVal = *minHeap.begin();
                int maxVal = *maxHeap.begin();

                minHeap.erase(minHeap.begin());
                maxHeap.erase(maxHeap.begin());
                minHeap.insert(maxVal);
                maxHeap.insert(minVal);
            }

            // cout << "get and " << endl;
            if (r - l == k - 1) {
                if (k % 2 == 1) {
                    res.push_back(*minHeap.begin());
                }
                else {
                    double avg = ((double)*maxHeap.begin() + (double)*minHeap.begin()) / 2;
                    res.push_back(avg);
                }
            }

            r ++;
        }

        return res;
    }
};