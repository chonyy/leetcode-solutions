class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> seen;
        int n = nums.size();

        for(string& s : nums) {
            seen.insert(s);
        }

        string res;
        string cur;

        find(0, n, cur, res, seen);

        return res;
    }

    bool find(int idx, int len, string& cur, string& res, unordered_set<string>& seen) {
        if(idx == len) {
            if(seen.count(cur)) {
                return false;
            }

            res = cur;
            return true;
        }

        // try 0
        cur += '0';
        if(find(idx + 1, len, cur, res, seen)) {
            return true;
        }
        cur.pop_back();

        // try 1
        cur += '1';
        if(find(idx + 1, len, cur, res, seen)) {
            return true;
        }
        cur.pop_back();

        return false;
    }
};