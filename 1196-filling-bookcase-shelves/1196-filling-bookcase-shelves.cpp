class Solution {
public:
    unordered_map<int,int> cache;

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        return minHeight(books, 0, shelfWidth);
    }

    int minHeight(vector<vector<int>>& books, int i, int shelfWidth) {
        if(i == books.size()) {
            // cout << "end" << endl;
            return 0;
        }
        if(cache.count(i)) {
            return cache[i];
        }

        // cout << "idx " << i << endl;
        int res = INT_MAX;
        int curHeight = 0;
        int remain = shelfWidth;

        for(int j = i; j < books.size(); j ++) {
            int w = books[j][0];
            int height = books[j][1];

            if(w > remain) {
                // cout << "break" << endl;
                break;
            }

            remain -= w;
            curHeight = max(curHeight, height);
            int nextHeight = minHeight(books, j+1, shelfWidth);

            // cout << "res " << res << endl;
            // cout << "curHeight " << curHeight << endl;
            // cout << "nextHeight " << nextHeight << endl;

            res = min(res, curHeight + nextHeight);
        }
        
        // cout << i << " res " << res << endl;;
        return cache[i] = res;
    }
};