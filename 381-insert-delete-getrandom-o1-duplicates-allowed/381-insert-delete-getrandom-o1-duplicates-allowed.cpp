class RandomizedCollection {
public:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> valIdx;
    
    RandomizedCollection() {
        
    }
    
    void printArr() {
        for(int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    void printMap() {
        for(auto& entry : valIdx) {
            cout << entry.first << ": ";
            for(int num : entry.second) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    bool insert(int val) {
        bool exist = valIdx.count(val) > 0;
        
        // add the idx to val
        // push into arr
        valIdx[val].insert(arr.size());
        arr.push_back(val);
        
        // printArr();
        // printMap();
        return !exist;
    }
    
    bool remove(int val) {
        if(valIdx.find(val) == valIdx.end()) {
            return false;
        }
        
        // replace last val to removeIdx
        auto removePos = valIdx[val].begin();
        int removeIdx = *removePos;
        int lastVal = arr.back();
        int lastPos = arr.size()-1;

        // remove old idx
        valIdx[val].erase(removeIdx);
        arr[removeIdx] = lastVal;
        valIdx[lastVal].insert(removeIdx);
        valIdx[lastVal].erase(lastPos);
        
        if(valIdx[val].size() == 0) {
            valIdx.erase(val);
        }
        arr.pop_back();
        
        // printArr();
        // printMap();
        return true;
    }
    
    int getRandom() {
        int r = rand() % arr.size();
        return arr[r];
    }
};

// val: idx, idx, idx

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */