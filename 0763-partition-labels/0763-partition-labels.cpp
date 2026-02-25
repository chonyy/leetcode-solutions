class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;

        for (int i = 0; i < s.size(); i ++) {
            last[s[i]] = i;
        }

        int partitionEnd = 0;
        int prev = 0;
        vector<int> res;

        for (int i = 0; i < s.size(); i ++) {
            partitionEnd = max(partitionEnd, last[s[i]]);

            if (i == partitionEnd) {
                res.push_back(i - prev + 1);
                prev = i+1;
            }
        }

        return res;
    }
};

// a b a b c b a c a d e f e g d 

