class Solution {
public:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int countVowelSubstrings(string word) {
        return atMost(word, 5) - atMost(word, 4);
    }

    int atMost(string& word, int k) {
        unordered_map<char,int> count;
        int n = word.size();
        int r = 0;
        int l = 0;
        int res = 0;

        while (r < n) {
            if (!vowels.contains(word[r])) {
                r ++;
                l = r;
                count.clear();
                continue;
            }

            count[word[r]] ++;
            while (count.size() > k) {
                count[word[l]] --;
                if (count[word[l]] == 0) {
                    count.erase(word[l]);
                }
                l ++;
            }

            res += r - l + 1;
            r ++;
        }

        return res;
    }
};