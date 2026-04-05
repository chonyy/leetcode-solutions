class DoublyNode {
public:
    int key;
    int val;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(int key, int value) {
        this->key = key;
        val = value;
    }
};

class LinkedList {
public:
    // left: new, right: old
    DoublyNode* left;
    DoublyNode* right;
    int cap;
    int size;

    LinkedList(int cap) {
        this->cap = cap;
        size = 0;
        left = new DoublyNode(0, 0);
        right = new DoublyNode(0, 0);
        left->next = right;
        right->prev = left;
    }

    DoublyNode* getRight() {
        return right->prev;
    }

    void remove(DoublyNode* node) {
        DoublyNode* prev = node->prev;
        DoublyNode* next = node->next;

        prev->next = next;
        next->prev = prev;

        size --;
    }

    void addToLeft(DoublyNode* node) {
        DoublyNode* next = left->next;

        left->next = node;
        node->prev = left;

        node->next = next;
        next->prev = node;

        size ++;
    }

    bool isFull() {
        return size == cap;
    }
};

class LRUCache {
    // map: key -> DoublyNode
    // doublyLinkedList: ll
private:
    unordered_map<int, DoublyNode*> map;
    LinkedList ll;
public:
    LRUCache(int capacity) : ll(capacity) {
    }
    
    int get(int key) {
        // check if contain in map
        // return -1 if not
        if (!map.contains(key)){
            return -1;
        }

        // get DoublyNode from map
        // remove from ll
        // push to front
        DoublyNode* node = map[key];
        ll.remove(node);
        ll.addToLeft(node);

        return node->val;
    }
    
    void put(int key, int value) {
        // check if contain in map
        // if yes, remove form ll and push to front
        if (map.contains(key)) {
            DoublyNode* node = map[key];
            node->val = value;
            ll.remove(node);
            ll.addToLeft(node);
            return;
        }

        // if full
        // get toDelete node from back
        // remove toDelete from ll
        // remove toDelete from map
        if (ll.isFull()) {
            DoublyNode* toDelete = ll.getRight();
            ll.remove(toDelete);
            map.erase(toDelete->key);
        }


        // create new DoublyNode and push to front
        // add entry in map
        DoublyNode* newNode = new DoublyNode(key, value);
        ll.addToLeft(newNode);
        map[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */