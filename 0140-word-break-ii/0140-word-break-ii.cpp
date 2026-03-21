class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<string> res;
        vector<string> temp;

        solve(s, 0, temp, words, res);

        return res;
    }

    void solve(string& s, int idx, vector<string>& temp, unordered_set<string>& words, vector<string>& res) {
        if (idx == s.size()) {
            string sentence = "";
            for (int i = 0; i < temp.size(); i ++) {
                if (i != 0) {
                    sentence += " ";
                }
                sentence += temp[i];
            }
            res.push_back(sentence);
            return;
        }

        for (int i = idx; i < s.size(); i ++) {
            int len = i - idx + 1;
            string sub = s.substr(idx, len);

            if (!words.contains(sub)) {
                continue;
            }

            // cout << "sub " << sub << endl;
            temp.push_back(sub);
            solve(s, i+1, temp, words, res);
            temp.pop_back();
        }
    }
};