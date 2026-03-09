class MyStack {
public:
    queue<int> q;

    MyStack() {
    }
    
    void push(int x) {
        q.push(x);

        for (int i = 0; i < q.size() - 1; i ++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//  push 1
//  push 2

//     back    3 2 1     front
//     =>

//     back  1 2 3 1 2    front


// queue: pop => 1

// stack: pop => 2