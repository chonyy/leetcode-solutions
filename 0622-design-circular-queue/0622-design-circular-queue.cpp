class Node {
public:
    int val;
    Node* next;

    Node(int x): val(x) {};
};

class MyCircularQueue {
private:
    Node* head;
    Node* tail;
    int cap;
    int size;

public:
    MyCircularQueue(int k) {
        head = new Node(0);
        tail = head;
        cap = k;
        size = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        
        Node* node = new Node(value);
        tail->next = node;
        tail = node;
        size ++;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        Node* next = head->next;

        if (tail == next) {
            tail = head;
        }

        head->next = head->next->next;
        delete next;
        size --;

        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return head->next->val;
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */