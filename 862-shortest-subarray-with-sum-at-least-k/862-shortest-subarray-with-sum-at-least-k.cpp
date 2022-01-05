class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long ans = INT_MAX;
        vector<long long> prefix(n+1, 0);
        
        // calculate prefix sum
        for(int i = 1; i <= n; i ++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        
        int r = 0;
        deque<long> deq;
        
        while(r <= n) {
            long long curSum = prefix[r];
            
            // get shortest possible
            while(!deq.empty() && curSum - prefix[deq.front()] >= k) {
                // cout << curSum << " " << prefix[deq.front()] << endl;
                // cout << curSum - prefix[deq.front()] << endl;
                ans = min(ans, r - deq.front());
                deq.pop_front();
            }
            
            // pop useless previous larger
            while(!deq.empty() && prefix[deq.back()] >= curSum) {
                deq.pop_back();
            }
            
            deq.push_back(r);
            r ++;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};

// 3 -2 5
// target = 4

// perfix: 0 1 3 11 10 15 21
// val:      1 2  8 -1  5  6
// target = 12
    
//  4  5 
//  15 21
    
// len = 4, sum = 14
// len = 3, sum = 12