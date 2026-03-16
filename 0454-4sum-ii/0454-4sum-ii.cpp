class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m;
        int res = 0;

        for(int a : A) {
            for(int b : B) {
                int sum = a + b;
                m[-sum] ++;
            }
        }

        for(int c : C) {
            for(int d : D) {
                int sum = c + d;
                res += m[sum];
            }
        }

        return res;
    }
};