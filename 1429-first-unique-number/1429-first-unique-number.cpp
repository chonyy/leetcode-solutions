class FirstUnique {
public:
    // num -> count
    // num -> list :: iterator (only exist when count is 1)

    unordered_map<int,int> count;
    unordered_map<int, list<int> :: iterator> numToIter;
    list<int> queue;

    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int showFirstUnique() {
        // return list front
        if (queue.empty()) {
            return -1;
        }

        return queue.front();
    }
    
    void add(int value) {
        // if count > 1, count ++
        if (count[value] > 1) {
            count[value] ++;
            return;
        }
        
        // if count[value] == 1
        //   remove from iterMap, count ++
        if (count[value] == 1) {
            queue.erase(numToIter[value]);
            numToIter.erase(value);
            count[value] ++;
            return;
        }

        // if count == 0
        //   push back
        //   map num to list back
        queue.push_back(value);
        numToIter[value] = prev(queue.end());
        count[value] = 1;

        return;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */