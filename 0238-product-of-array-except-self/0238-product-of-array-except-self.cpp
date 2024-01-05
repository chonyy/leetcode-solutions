class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProd(n, 1);
        vector<int> rightProd(n, 1);
        vector<int> res;
        
        for(int i = 1; i < n; i ++) {
            int ri = (n-1) - i;
            leftProd[i] = nums[i-1] * leftProd[i-1];
            rightProd[ri] = nums[ri+1] * rightProd[ri+1];
        }
        
        for(int i = 0; i < n ; i++) {
            // cout << leftProd[i] << " " << rightProd[i] << endl;
            res.push_back(leftProd[i] * rightProd[i]);
        }
        
        return res;
    }
};


// 1 2 3 4
// 24 12 4 1    
// 1 1 2 6  