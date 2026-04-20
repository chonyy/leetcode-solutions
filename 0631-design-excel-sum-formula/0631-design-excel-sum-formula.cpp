class Cell {
private:
    int val;
    int cache;
    bool dirty;
    unordered_map<Cell*, int> relations;
public:
    unordered_set<Cell*> parents;

    Cell(int val) {
        this->val = val;
        cache = val;
        dirty = false;
    }

    void addRel(Cell* cell) {
        relations[cell] ++;
        cell->parents.insert(this);
    }

    int getVal() {
        if (relations.empty()) {
            return val;
        }

        if (!dirty) {
            return cache;
        }

        int res = 0;

        for (auto& entry : relations) {
            res += entry.second * entry.first->getVal();
        }

        cache = res;
        dirty = false;
        return res;
    }

    void markDirty() {
        dirty = true;
        for (Cell* p : parents) {
            p->markDirty();
        }
    }

    void setVal(int val) {
        for (auto& entry : relations) {
            entry.first->parents.erase(this);
        }
        relations.clear();

        markDirty();
        this->val = val;
        dirty = false;
        cache = val;
    }
};

class Excel {
public:
    vector<vector<Cell*>> table;

    Excel(int height, char width) {
        int w = width - 'A';
        table = vector<vector<Cell*>>(height+1, vector<Cell*>(w+1));

        for (int i = 0; i <= height; i ++) {
            for (int j = 0; j <= w; j ++) {
                table[i][j] = new Cell(0);
            }
        }
    }
    
    void set(int row, char column, int val) {
        table[row][column - 'A']->setVal(val);
    }
    
    int get(int row, char column) {
        return table[row][column - 'A']->getVal();
    }
    
    int sum(int row, char column, vector<string> numbers) {
        int w = column - 'A';
        table[row][w]->setVal(0);
        for (auto& range : numbers) {
            vector<pair<int,int>> positions = getPos(range);
            int startR = positions[0].first;
            int endR = positions[1].first;
            int startC = positions[0].second;
            int endC = positions[1].second;

            for (int i = startR; i <= endR; i ++) {
                for (int j = startC; j <= endC; j ++) {
                    table[row][w]->addRel(table[i][j]);
                }
            }
        }

        table[row][w]->markDirty();
        return table[row][w]->getVal();
    }

    vector<pair<int,int>> getPos(string& s) {
        int startC = s[0] - 'A';
        int i = 1;
        int startR = 0;
        while (i < s.size() && s[i] != ':') {
            startR *= 10;
            startR += s[i] - '0';
            i ++;
        }

        if (i == s.size()) {
            return {{startR, startC}, {startR, startC}};
        }

        i ++;

        int endC = s[i] - 'A';
        i ++;

        int endR = 0;
        while (i < s.size()) {
            endR *= 10;
            endR += s[i] - '0';
            i ++;
        } 

        return {{startR, startC}, {endR, endC}};
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */