class Solution {
public:
    unordered_map<int, int> m;
    int tribonacci(int n) {
        if(n < 2)
            return n;
        if(n == 2)
            return 1;
        if(m[n])
            return m[n];
        
        int ans = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        return m[n] = ans;
    }
};