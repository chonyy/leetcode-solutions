class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int res = 0;

        for(int i = 0; i < n; i ++) {
            int num = rating[i];

            int smaller = 0;
            for(int j = 0; j < i; j ++) {
                if(rating[j] < num) {
                    smaller ++;
                }
            }

            int larger = 0;
            for(int j = i+1; j < n; j ++) {
                if(rating[j] > num) {
                    larger ++;
                }
            }

            res += smaller * larger;
            res += (i - smaller) * ((n - i - 1) - larger);
        }

        return res;
    }
};