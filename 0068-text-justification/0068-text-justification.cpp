class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int wordIdx = 0;
        int n = words.size();
        vector<string> res;

        while (wordIdx < n) {
            pair<bool, int> line = wordOnLine(words, wordIdx, maxWidth);
            bool lastLine = line.first;
            int wordCount = line.second;
            // cout << "word count " << wordCount << endl;

            string newLine = constuctLine(words, wordIdx, wordCount, lastLine, maxWidth);
            res.push_back(newLine);
            wordIdx += wordCount;
        }

        return res;
    }

    string constuctLine(vector<string>& words, int wordIdx, int wordCount, bool lastLine, int maxWidth) {
        if (wordCount == 1) {
            return words[wordIdx] + string(maxWidth - words[wordIdx].size(), ' ');
        }

        if (lastLine) {
            string res = "";

            for (int i = 0; i < wordCount; i ++) {
                if (i) {
                    res += ' ';
                }
                res += words[wordIdx + i];
            }
            int remain = maxWidth - res.size();
            res += string(remain, ' ');

            return res;
        }

        int charCount = 0;
        for (int i = 0; i < wordCount; i ++) {
            charCount += words[wordIdx + i].size();
        }

        int spaceCount = maxWidth - charCount;
        int spaceEach = wordCount == 1 ? spaceCount : spaceCount / (wordCount - 1);
        int extra = wordCount == 1 ? 0 : spaceCount % (wordCount - 1);

        string res = "";

        for (int i = 0; i < wordCount; i ++) {
            res += words[wordIdx + i];

            if (i != wordCount - 1) {
                res += string(spaceEach, ' ');
                if (extra) {
                    res += ' ';
                    extra --;
                }
            }
        }

        return res;
    }

    pair<bool, int> wordOnLine(vector<string>& words, int wordIdx, int maxWidth) {
        int space = 0;
        int taken = 0;
        // cout << "word" << endl;

        while (wordIdx + taken < words.size()) {
            int need = words[wordIdx + taken].size() + (taken > 0);
            if (space + need > maxWidth) {
                break;
            }

            if (taken) {
                space ++;
            }
            space += words[wordIdx + taken].size();
            // cout << "took " << wordIdx + taken << endl;
            // cout << "space " << space << endl;

            taken ++;
        }

        bool lastLine = wordIdx + taken == words.size();

        return {lastLine, taken};
    }
};

// wordIdx starting at 0

// wordOnLine(words, wordIdx, maxWidth) => <lastLine: bool, words: int>
// - loop wordIdx with space padding until can't fit in maxWidth
// - is lastLine if wordIdx == words.size();

// constructLine(words, wordCount, lastLine) => string with words based on space padding
// - caculate charCount => spaceCount = maxWidth - charCount
// - evenly distribute spaceCount after each word

// spaceCount = 5
// words = 3

// spaceEachWord = spaceCount / (words - 1)
// extra = spaceConunt % (words -1)


// wordIdx += wordCount
