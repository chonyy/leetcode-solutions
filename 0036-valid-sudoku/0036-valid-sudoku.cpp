class Solution {
public:
    int rows, cols;
    vector<unordered_set<int>> usedRow;
    vector<unordered_set<int>> usedCol;
    vector<unordered_set<int>> usedBox;
    
    bool check(int i, int j, char ele) {    
        if(ele == '.')
            return true;
        
        int val = ele - '0';
        int row = i / 3;
        int col = j / 3;
        int idx = row*3 + col;
        
        if(usedRow[i].count(val))
            return false;
         if(usedCol[j].count(val))
            return false;
        
        if(usedBox[idx].count(val)) {
            return false;
        }
        
        usedRow[i].insert(val);
        usedCol[j].insert(val);
        usedBox[idx].insert(val);
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        rows = board.size();
        cols = board.size();
        usedRow = vector<unordered_set<int>>(9);
        usedCol = vector<unordered_set<int>>(9);
        usedBox = vector<unordered_set<int>>(9);
        
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(check(i, j, board[i][j]) == false) {
                    return false;
                }
            }    
        }   
       
        return true;
    }
};