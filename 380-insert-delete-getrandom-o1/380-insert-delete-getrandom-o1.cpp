class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int,int> valIdx;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valIdx.count(val))
            return false;
        
        valIdx[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(valIdx.count(val) == 0) {
            return false;
        }
        
        int removeIdx = valIdx[val];
        int lastVal = arr.back();
        
        // put lastVal on removeIdx
        // update valIdx of lastVal to removeIdx
        arr[removeIdx] = lastVal;
        valIdx[lastVal] = removeIdx;
        
        // erase val from hashmap
        valIdx.erase(val);
        // shrink arr
        arr.pop_back();
        
        return true;
    }
    
    int getRandom() {
        int r = rand() % arr.size();
        return arr[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */