class TicTacToe {
public:
    int size;
    vector<int> rows;
    vector<int> cols;
    int posDiag = 0;
    int negDiag = 0;

    TicTacToe(int n) {
        size = n;
        rows.resize(size);
        cols.resize(size);
    }
    
    int move(int row, int col, int player) {
        // cout << row << " " << col << " " << player << endl;
        int change = player == 1 ? 1 : -1;

        rows[row] += change;
        cols[col] += change;
        
        if (row + col == size - 1) {
            posDiag += change;
        }

        if (row - col == 0) {
            negDiag += change;
        }

        // cout << rows[row] << " " << cols[col] << " " << posDiag << " " << negDiag << endl;
        if (rows[row] == size || cols[col] == size || posDiag == size || negDiag == size) {
            return 1;
        }
        if (rows[row] == -size || cols[col] == -size || posDiag == -size || negDiag == -size) {
            return 2;
        }

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */