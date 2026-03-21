class Solution {
public:
    unordered_map<int, vector<string>> cache;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return solve(s, 0, words);
    }

    vector<string> solve(string& s, int idx, unordered_set<string>& words) {
        if (idx == s.size()) {
            return {""};
        }

        if (cache.contains(idx)) {
            return cache[idx];
        }

        vector<string> res;
        for (int i = idx; i < s.size(); i ++) {
            int len = i - idx + 1;
            string left = s.substr(idx, len);

            if (!words.contains(left)) {
                continue;
            }

            vector<string> right = solve(s, i+1, words);
            
            for (string& r : right) {
                string sentence = left;
                if (r.size() > 0) {
                    sentence += " ";
                    sentence += r;
                }
                res.push_back(sentence);
            }
        }

        cache[idx] = res;
        return res;
    }
};