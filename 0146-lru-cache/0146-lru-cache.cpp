class LRUCache {
public:
    // doubly linked list
    // hashmap from key to iterator for fast access
    int capacity;
    list<pair<int,int>> recent;
    unordered_map<int, list<pair<int,int>> ::iterator> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) {
        // printList();
        // get from hashmap 
        // if no contain, return -1
        if (!cache.contains(key)) {
            return -1;
        }

        // if yes
        // move iterator to the front
        // update map with new iterator
        refresh(key);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        // printList();
        // check contains in map
        // if yes, move iterator to front
        // update map with new iterator
        if (cache.contains(key)) {
            refresh(key);
            recent.begin()->second = value;
            return;
        }

        // if no

        // if full
        // get back iterator
        // pop back
        // remove from cache
        // cout << "size " << recent.size() << " " << capacity << endl;
        if (recent.size() == capacity) {
            auto toDelete = recent.back();
            recent.pop_back();
            cache.erase(toDelete.first);
        }

        // push to list front
        // add to hashmap
        recent.push_front({key, value});
        cache[key] = recent.begin();
    }

    void refresh(int key) {
        auto it = cache[key];
        recent.splice(recent.begin(), recent, it);
        cache[key] = recent.begin();
    }

    void printList() {
        for (auto it = recent.begin(); it != recent.end(); it ++) {
            cout << it->first << " ";
        }

        cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */