class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int end = n + k - 1;;
        int l = 0;
        int r = 1;
        int res = 0;

        while(r < end) {
            if(colors[r % n] == colors[(r - 1) % n]) {
                l = r;
            }
            else if(r - l + 1 == k) {
                res ++;
                l ++;
            }
            
            r ++;
        }

        return res;
    }
};