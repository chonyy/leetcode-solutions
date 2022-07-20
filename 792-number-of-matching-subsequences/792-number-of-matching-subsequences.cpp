class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int sum = 0;
        vector<vector<int>> indexes(26);

        for(int i = 0; i < S.size(); i ++) {
            char c = S[i];
            indexes[c - 'a'].push_back(i);
        }

        for(string word : words) {
            sum += check(S, word, indexes);
        }

        return sum;
    }

    bool check(string& s, string& word, vector<vector<int>>& indexes) {
        int cur = -1;
        for(char c : word) {
            auto loc = lower_bound(indexes[c - 'a'].begin(), indexes[c - 'a'].end(), cur);
            if(loc == indexes[c - 'a'].end())
                return false;
            cur = *loc + 1;
        }
        return true;
    }
};