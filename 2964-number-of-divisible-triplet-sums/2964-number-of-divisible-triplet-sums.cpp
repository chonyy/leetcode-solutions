class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i ++) {
            unordered_map<int,int> seen;
            for (int j = i + 1; j < n; j ++) {
                int cur = (nums[i] + nums[j]) % d;
                int target = (- nums[j] % d + d) % d;

                // cout << "j " << j << endl;
                // cout << "cur " << cur << endl;
                // cout << "target " << target << endl;
                
                res += seen[target];

                seen[cur] ++;
            }
        }
        
        return res;
    }
};


// 3,3,4,7,8
// i
//   l.    r

// 14 % 5 = 4

// 1 

// nums[i] + nums[j] % d ==  (d - nums[k]) % d