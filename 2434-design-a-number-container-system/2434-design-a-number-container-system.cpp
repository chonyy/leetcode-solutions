class NumberContainers {
public:
    unordered_map<int,set<int>> m;
    unordered_map<int,int> idxToNum;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int originalNum = getOriginalNumber(index);

        if(originalNum != -1) {
            m[originalNum].erase(index);
            if(m[originalNum].size() == 0) {
                m.erase(originalNum);
            }
        }

        idxToNum[index] = number;
        m[number].insert(index);
    }
    
    int find(int number) {
        if(m.count(number) == 0)
            return -1;

        return *m[number].begin();
    }

    int getOriginalNumber(int index) {
        if(idxToNum.find(index) == idxToNum.end()) {
            return -1;
        }

        return idxToNum[index];
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */