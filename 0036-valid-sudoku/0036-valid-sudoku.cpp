class Solution {
public:
    int rows;
    int cols;
    vector<unordered_set<int>> rowUsed;
    vector<unordered_set<int>> colUsed;
    vector<unordered_set<int>> boxUsed;
    
    bool isValid(int row, int col, char c) {
        if(c == '.') {
            return true;
        }
        
        int num = c - '0';
        int idx = (row / 3) * 3 + col / 3;
        
        if(rowUsed[row].contains(num)) {
            return false;
        }
        
        if(colUsed[col].contains(num)) {
            return false;
        }
        
        if(boxUsed[idx].contains(num)) {
            return false;
        }
        
        rowUsed[row].insert(num);
        colUsed[col].insert(num);
        boxUsed[idx].insert(num);
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        rows = board.size();
        cols = board.size();
        
        rowUsed = vector<unordered_set<int>>(rows);
        colUsed = vector<unordered_set<int>>(cols);
        boxUsed = vector<unordered_set<int>>(rows);
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(isValid(i, j, board[i][j]) == false) {
                    return false;
                }
            }
        }
    
        return true;
    }
};