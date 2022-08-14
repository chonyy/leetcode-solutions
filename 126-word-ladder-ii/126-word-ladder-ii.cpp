class Solution
{
    private:
        vector<vector<string>> res;
        vector<string> backPath;
        unordered_map<string, int> wordDist;
        string begin;
        
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
        {
            unordered_set<string> dict(wordList.begin(), wordList.end());
            begin = beginWord;
            queue<string> q;

            int wordLen = beginWord.size();
            q.push({beginWord});
            wordDist[beginWord] = 0;

            // 1. Find the shortest path distance from beginWord to the word in the wordList
            while (!q.empty()) 
            {
                int size = q.size();
                for(int i = 0; i < size; i ++) {
                    string curWord = q.front();
                    q.pop();
                    
                    // Go through neighbors
                    for (int i = 0; i < wordLen; i++)
                    {
                        string temp = curWord;
                        for (char c = 'a'; c <= 'z'; c++)
                        {
                            temp[i] = c;
                            if (!wordDist.count(temp) && dict.count(temp)) {
                                wordDist[temp] = wordDist[curWord] + 1;
                                q.push(temp);
                            }
                        }
                    }
                }
            }
            if (wordDist.count(endWord))
                backtrack(endWord);
            return res;
        }

        // 2. Find path from endWord to beginWord
        void backtrack(string word)
        {
            backPath.push_back(word);
            if (word == begin)
            {
                vector<string> resPath = backPath;
                reverse(resPath.begin(), resPath.end());
                res.push_back(resPath);
                backPath.pop_back();
                return;
            }
            
            // Go through neighbors
            int curDist = wordDist[word];
            for (int i = 0; i < word.size(); i++)
            {
                char originalC = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (wordDist[word] == curDist - 1)
                        backtrack(word);
                }
                word[i] = originalC;
            }
            backPath.pop_back();
            return;
        }
};