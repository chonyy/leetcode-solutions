class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> seen;
        int res = 0;

        for(int num : arr) {
            seen.insert(num);
        }

        for(int i = 0; i < n - 1; i ++) {
            for(int j = i + 1; j < n; j ++) {
                int prev = arr[i];
                int cur = arr[j];
                int len = 2;
                int next = prev + cur;

                while(seen.count(next)) {
                    len ++;
                    
                    prev = cur;
                    cur = next;
                    next = prev + cur;
                }

                if(len >= 3) {
                    res = max(res, len);
                }
            }
        }

        return res;
    }
};