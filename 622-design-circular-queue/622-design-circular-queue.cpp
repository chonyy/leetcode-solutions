class MyCircularQueue {
private:
    int head = 0;
    int tail = -1;
    int len = 0;
    vector<int> data;
public:
    MyCircularQueue(int k) {
        data = vector<int>(k);
    }
    bool enQueue(int val) {
        if (isFull()) 
            return false;

        tail = (tail + 1) % data.size();
        len ++;
        data[tail] = val;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) 
            return false;
        
        head = (head + 1) % data.size();
        len --;
        return true;
    }
    int Front() {
        return isEmpty() ? -1 : data[head];
    }
    int Rear() {
        return isEmpty() ? -1 : data[tail];
    }
    bool isEmpty() {
        return len == 0;
    }
    bool isFull() {
        return len == data.size();
    }
};