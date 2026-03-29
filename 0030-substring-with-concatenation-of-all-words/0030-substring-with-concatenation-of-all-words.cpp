class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sLen = s.size();
        int n = words.size();
        int len = words[0].size();
        int requireLen = n * len;

        // count words
        unordered_map<string, int> count;
        for (auto& w : words) {
            count[w] ++;
        }

        vector<int> res;

        // from 0 to len-1, try sliding window
        // window move len at a time
        // in window, get substr from right with len to get toCheck, seen[toCheck] ++ and matched ++
        // while seen[toCheck] > coutn[toCheck], get left word, seen[leftWord] -- and matched --
        // if matched == n, get res
        for (int i = 0; i < len; i ++) {
            int r = i;
            int l = i;
            unordered_map<string,int> seen;
            int matched = 0;

            while (r < sLen) {
                string toCheck = s.substr(r, len);
                // found word not in count, restart
                if (!count.contains(toCheck)) {
                    seen.clear();
                    matched = 0;
                    r += len;
                    l = r;
                    continue;
                }

                seen[toCheck] ++;
                matched ++;

                while (seen[toCheck] > count[toCheck]) {
                    string leftWord = s.substr(l, len);
                    seen[leftWord] --;
                    matched --;
                    l += len;
                }

                if (matched == n) {
                    res.push_back(l);
                }

                r += len;
            }
        }

        return res;
    }
};


// bar foothefoobarman
// j