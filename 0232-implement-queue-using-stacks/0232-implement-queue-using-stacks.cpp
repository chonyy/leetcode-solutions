class MyQueue {
public:
    stack<int> pushQueue;
    stack<int> popQueue;

    MyQueue() {

    }
    
    void push(int x) {
        pushQueue.push(x);
    }
    
    int pop() {
        // move all remaining elements to pop queue
        if (popQueue.empty()) {
            while (!pushQueue.empty()) {
                popQueue.push(pushQueue.top());
                pushQueue.pop();
            }
        }

        // if popQueue is not empty, old ones are still in there
        int val = popQueue.top();
        popQueue.pop();
        return val;
    }
    
    int peek() {
        if (popQueue.empty()) {
            while (!pushQueue.empty()) {
                popQueue.push(pushQueue.top());
                pushQueue.pop();
            }
        }

        return popQueue.top();
    }
    
    bool empty() {
        return pushQueue.empty() && popQueue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// push 1
// push 2
// push 3

// stack:

//  top   5 3 2       bottom

//  top    2 3        bottom