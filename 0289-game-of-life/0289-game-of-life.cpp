class Solution {
public:
    int rows;
    int cols;
    vector<pair<int,int>> dirs = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1},{1,-1}, {1,0}, {1,1}};
    void gameOfLife(vector<vector<int>>& board) {
        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                int neighbors = countNeighbors(board, i, j);

                if (board[i][j] & 1) { // live
                    if (neighbors < 2) {
                        continue;
                    }
                    if (neighbors == 2 || neighbors == 3) {
                        board[i][j] += 2;
                    }
                    if (neighbors > 3) {
                        continue;
                    }
                }
                else { // dead
                    if (neighbors == 3) {
                        board[i][j] += 2;
                    }
                }
            }
        }

        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }

    int countNeighbors(vector<vector<int>>& board, int r, int c) {
        int res = 0;

        for (auto& dir : dirs) {
            int newR = r + dir.first;
            int newC = c + dir.second;

            // boundary check
            if (newR < 0 | newR >= rows || newC < 0 || newC >= cols) {
                continue;
            }

            res += board[newR][newC] & 1;
        }

        return res;
    }
};