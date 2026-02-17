class Solution {
public:
    int rows;
    int cols;
    char placeholder = 'p';

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        // set placeholder from edge
        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (i == 0 || i == rows-1 || j == 0 || j == cols-1) {
                    dfs(board, i, j);
                }
            }
        }

        // set all unmarked O to X
        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }

                if (board[i][j] == placeholder) {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int r, int c) {
        // boundary check
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        if (board[r][c] != 'O') {
            return;
        }

        board[r][c] = placeholder;

        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
};