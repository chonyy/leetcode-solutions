class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int l = 0;
        int r = 0;
        int n = nums.size();
        vector<int> res;

        while (r < n) {
            // pop all smaller number in dq
            while(!dq.empty() && dq.back() < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(nums[r]);

            // if k size, record number and move l
            // remove out out bound elements
            int len = r - l + 1;
            if (len == k) {
                res.push_back(dq.front());
                
                if (nums[l] == dq.front()) {
                    dq.pop_front();
                }
                l ++;
            }

            // move r
            r ++;
        }

        return res;
    }
};


// Solution 1

// brute force: looping through all n * k position

// time: O(n * k)
// space: O(1)


// Solution 2

// keep tracking of a running priority queue

// time: O(NlogN)
// space: O(N)


// Solution 3

// 3 7 5 5 6 7
//       i 

// stack: 7 5 5

// res: 7

// store all numbers in X

// pop all numbers smaller than current

// when reach k size: res = max(res, stack.top())

