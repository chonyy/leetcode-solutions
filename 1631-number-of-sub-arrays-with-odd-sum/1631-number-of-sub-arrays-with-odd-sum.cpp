class Solution {
public:
    int mod = pow(10,9) + 7;
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0;
        int even = 0;
        int res = 0;

        for(int num : arr) {
            bool isOdd = num % 2;

            if(isOdd) {
                swap(even, odd);
                odd ++;
            }
            else {
                even ++;
            }
            
            res = (res + odd) % mod;
        }

        return res;
    }
};