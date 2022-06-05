class Solution {
public:
    int res = 0;
    unordered_set<int> cols;
    unordered_set<int> posDiag; // r - c
    unordered_set<int> negDiag; // r + c
    
    bool isValid(vector<string>& board, int row, int col) {
        if(cols.count(col) || posDiag.count(row - col) || negDiag.count(row + col))
            return false;
        return true;
    }
    
    void backtrack(vector<string>& board, int row, int n) {
        if(row == n) {
            res ++;
            return;
        }
        
        for(int i = 0; i < n; i ++) {
            if(!isValid(board, row, i))
                continue;
            
            board[row][i] = 'Q';
            cols.insert(i);
            posDiag.insert(row - i);
            negDiag.insert(row + i);
            
            backtrack(board, row+1, n);
            
            board[row][i] = '.';
            cols.erase(i);
            posDiag.erase(row - i);
            negDiag.erase(row + i);
        }
    }
    
    int totalNQueens(int n) {
        vector<string> board(n, string(n , '.'));
        
        backtrack(board, 0, n);
        
        return res;
    }
};