class MyHashSet {
public:
    int size = 10000;
    vector<list<int>> data;

    MyHashSet() {
        data = vector<list<int>>(size);
    }
    
    void add(int key) {
        if (contains(key)) {
            return;
        }

        int keyInData = key % size;
        data[keyInData].push_back(key);
    }
    
    void remove(int key) {
        int keyInData = key % size;

        for (auto& entry : data[keyInData]) {
            if (entry == key) {
                data[keyInData].remove(entry);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int keyInData = key % size;

        for (auto& entry : data[keyInData]) {
            if (entry == key) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */