class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> valToIdx;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // check hashmap, return -1 if exists
        if (valToIdx.contains(val)) {
            return false;
        }

        // push back to nums
        // udpate valToIdx
        nums.push_back(val);
        valToIdx[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        // check hashmap, return -1 if exists
        if (!valToIdx.contains(val)) {
            return false;
        }

        // get idx of val
        // get lastVal
        // swap last item with idx
        // valToIdx[lastVal] = idx
        // remove val from hashmap
        // nums pop back
        int idx = valToIdx[val];
        int lastVal = nums.back();
        swap(nums[idx], nums[nums.size() - 1]);

        valToIdx[lastVal] = idx;
        valToIdx.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        // idx = getRand() % size of num
        // return nums with idx
        int idx = rand() % nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */