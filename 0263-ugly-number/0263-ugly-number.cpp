class Solution {
public:
    bool isUgly(int n) {
        if(n == 0)
            return false;
        vector<int> factors = {2, 3, 5};
        
        for(int num : factors) {
            while(n % num == 0)
                n /= num;
        }
        
        return n == 1;
    }
};