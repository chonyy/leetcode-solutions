class MyHashMap {
public:
    int size = 10000;
    vector<list<pair<int,int>>> data;

    MyHashMap() {
        data.resize(size);
    }
    
    void put(int key, int value) {
        int bucket = key % size;
        
        for (auto& entry : data[bucket]) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }

        data[bucket].push_back({key, value});
    }
    
    int get(int key) {
        int bucket = key % size;

        for (auto& entry : data[bucket]) {
            if (entry.first == key) {
                return entry.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int bucket = key % size;
        for (auto it = data[bucket].begin(); it != data[bucket].end(); it ++) {
            if ((*it).first == key) {
                data[bucket].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */