class Cell {
    public:
        int val;
        int row;
        int col;
        unordered_map<Cell*, int> relations;
    
        Cell(int val, int row, int col) {
            this->val = val;
            this->row = row;
            this->col = col;
        }   
        
        void addRel(Cell* cell) {
            this->relations[cell] ++;
        }
    
        int getVal() {
            if(relations.empty()) {
                return val;
            }
            
            int sum = 0;
            for(auto entry : relations) {
                // cout << entry.second << " " << entry.first->getVal() << endl;
                sum += entry.second * entry.first->getVal();   
            }
            return sum;
        }
    
        void set(int val) {
            this->val = val;
            relations.clear();
        }
};

class Excel {
public:
    vector<vector<Cell*>> mat;
    Excel(int height, char width) {
        int w = width - 'A';
        mat = vector<vector<Cell*>>(height+1, vector<Cell*>(w+1));
        for(int i = 0; i <= height; i ++) {
            for(int j = 0; j <= w; j ++) {
                mat[i][j] = new Cell(0, i, j);
            }
        }
    }
    
    void set(int row, char column, int val) {
        int w = column - 'A';
        mat[row][w]->set(val);
    }
    
    int get(int row, char column) {
        int w = column - 'A';
        return mat[row][w]->getVal();
    }
    
    void add(Cell* cell, string& str) {
        auto idx = str.find(":");
        
        if(idx == string::npos) {
            int w = str[0] - 'A';
            string sub = str.substr(1);
            int r = stoi(sub);
            auto toAdd = mat[r][w];
            cell->addRel(toAdd);
        }
        else {
            int w1 = str[0] - 'A';
            string sub1 = str.substr(1, idx-1);
            int r1 = stoi(sub1);
            
            int w2 = str[idx+1] - 'A';
            string sub2 = str.substr(idx+2);
            int r2 = stoi(sub2);
            
            for(int i = r1; i <= r2; i ++) {
                for(int j = w1; j <= w2; j ++) {
                    // cout << i << " " << j << endl;
                    cell->addRel(mat[i][j]);
                }
            }
        }
    }
    
    int sum(int row, char column, vector<string> numbers) {
        int w = column -= 'A';
        auto cell = mat[row][w];
        
        cell->relations.clear();
        for(auto& num : numbers) {
            add(cell, num);
        }
        
        return cell->getVal();
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */