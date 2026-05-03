class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // loop with sliding window
        // put r in max heap. If overflow, pop to minHeap
        // remove l from set
        // if remove from maxHeap, pop min to max
        // if remove from minHeap, no action
        int n = nums.size();
        int l = 0;
        int r = 0;
        vector<double> res;
        multiset<int> first;
        multiset<int> second; 

        while (r < n) {
            int num = nums[r];
            first.insert(num);
            if (first.size() > k / 2) {
                second.insert(*first.rbegin());
                first.erase(first.find(*first.rbegin()));
            }

            // get res and remove l
            if (r - l == k - 1) {
                // get res
                if (k % 2 == 1) {
                    res.push_back(*second.begin());
                }
                else {
                    res.push_back(((double)*first.rbegin() + (double)*second.begin()) / 2);
                }

                // remove l and rebalance
                int toRemove = nums[l];
                if (second.contains(toRemove)) {
                    second.erase(second.find(toRemove));
                }
                else {
                    first.erase(first.find(toRemove));
                    first.insert(*second.begin());
                    second.erase(second.begin());
                }
                l ++;
            }

            r ++;
        }

        return res;
    }
};