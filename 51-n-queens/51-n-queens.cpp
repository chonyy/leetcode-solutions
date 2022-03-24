class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> posDiag; // r - c
    unordered_set<int> negDiag; // r + c
    
    bool isValid(vector<string>& board, int row, int col) {
        if(cols.count(col) || posDiag.count(row - col) || negDiag.count(row + col))
            return false;
        return true;
    }
    
    void backtrack(vector<string>& board, vector<vector<string>>& res, int row, int n) {
        if(row == n) {
            res.push_back(board);
            return;
        }
        
        for(int i = 0; i < n; i ++) {
            if(!isValid(board, row, i))
                continue;
            
            board[row][i] = 'Q';
            cols.insert(i);
            posDiag.insert(row - i);
            negDiag.insert(row + i);
            
            backtrack(board, res, row+1, n);
            
            board[row][i] = '.';
            cols.erase(i);
            posDiag.erase(row - i);
            negDiag.erase(row + i);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n , '.'));
        
        backtrack(board, res, 0, n);
        
        return res;
    }
};