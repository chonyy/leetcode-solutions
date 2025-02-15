class Solution {
public:
    int punishmentNumber(int n) {
        int res = 0;

        for(int i = 1; i <= n; i ++) {
            int sq = i * i;
            if(partition(0, 0, i, to_string(i * i)))
                res += sq;
        }

        return res;
    }

    bool partition(int idx, int cur, int target, string sq) {
        if(idx == sq.size() &&  cur == target)
            return true;

        if(idx == sq.size())
            return false;

        
        for(int i = idx; i < sq.size(); i ++) {
            string sub = sq.substr(idx, i - idx + 1);
            int newNum = stoi(sub);
            if(partition(i + 1, cur + newNum, target, sq))
                return true;
        }

        return false;
    }
};