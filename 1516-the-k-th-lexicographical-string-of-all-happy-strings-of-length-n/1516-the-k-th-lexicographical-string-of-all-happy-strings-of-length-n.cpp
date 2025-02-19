class Solution {
public:
    string getHappyString(int n, int k) {
        int count = 0;
        string cur;
        string res = "";

        getHappy(n, k, count, cur, res);

        return res;
    }

    bool getHappy(int n, int k, int& count, string& cur, string& res) {
        if(cur.size() == n) {
            count ++;

            if(count == k) {
                res = cur;
                return true;
            }

            return  false;
        }

        for(char c = 'a'; c <= 'c'; c ++) {
            if(cur.size() != 0 && cur.back() == c) {
                continue;
            }

            cur += c;
            
            if(getHappy(n, k, count, cur, res)) {
                return true;
            }

            cur.pop_back();
        }

        return false;
    }
};