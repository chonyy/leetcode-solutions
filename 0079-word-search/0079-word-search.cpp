class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) {
            return false;
        }

        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> used(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (find(used, board, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool find(vector<vector<bool>>& used, vector<vector<char>>& board, int r, int c, string word, int idx) {
        if (idx == word.size()) {
            return true;
        }

        if (r < 0 || r >= board.size()) {
            return false;
        }
        if (c < 0 || c >= board[0].size()) {
            return false;
        }

        if (used[r][c]) {
            return false;
        }

        if (word[idx] != board[r][c]) {
            return false;
        }

        used[r][c] = true;
        for (auto& dir : dirs) {
            int newR = r + dir[0];
            int newC = c + dir[1];
            
            if (find(used, board, newR, newC, word, idx+1)) {
                return true;
            }
        }
        used[r][c] = false;

        return false;
    }
};