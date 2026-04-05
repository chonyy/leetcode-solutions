class LRUCache {
    // map: key -> DoublyNode
    // doublyLinkedList: ll
private:
    unordered_map<int, list<pair<int,int>> :: iterator> map;
    list<pair<int,int>> ll;
    int cap;
    int size;
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        // check if contain in map
        // return -1 if not
        if (!map.contains(key)) {
            return -1;
        }

        // get DoublyNode from map
        // remove from ll, push to front
        // reset iterator
        auto it = map[key];
        ll.splice(ll.begin(), ll, it);
        map[key] = ll.begin();

        return it->second;
    }
    
    void put(int key, int value) {
        // check if contain in map
        // if yes, remove form ll and push to front
        // set the value
        // reset iterator
        if (map.contains(key)) {
            auto it = map[key];
            it->second = value;
            ll.splice(ll.begin(), ll, it);
            map[key] = ll.begin();
            return;
        }

        // if full
        // get toDelete node from back
        // remove toDelete key from map
        // remove toDelete from ll
        if (size == cap) {
            auto toDelete = ll.back();
            map.erase(toDelete.first);
            ll.pop_back();
            size --;
        }

        // create new DoublyNode and push to front
        // add entry in map
        // increment size
        pair<int,int> newNode = {key, value};
        ll.push_front(newNode);
        map[key] = ll.begin();
        size ++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */