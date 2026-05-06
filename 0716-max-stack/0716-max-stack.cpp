class MaxStack {
public:
    // stack as doubly linked list
    // ordered map value: stack<list :: iterator>

    list<int> stk;
    map<int, stack<list<int> :: iterator>> valToIters;

    MaxStack() {
        
    }
    
    void push(int x) {
        // push to list
        // push iterator map[value] stack
        stk.push_back(x);
        valToIters[x].push(prev(stk.end()));
    }
    
    int pop() {
        // get list.back() and pop_back
        // map[value].pop_back();
        int val = stk.back();
        stk.pop_back();

        valToIters[val].pop();
        if (valToIters[val].size() == 0) {
            valToIters.erase(val);
        }

        return val;
    }
    
    int top() {
        // stack.back()
        return stk.back();
    }
    
    int peekMax() {
        // get max from map.rbegin()->first
        return valToIters.rbegin()->first;
    }
    
    int popMax() {
        // get max from peekMax
        // get iterator from map[max].top()
        // list.erase(iterator)
        // map[max].pop()
        int maxVal = peekMax();
        auto it = valToIters[maxVal].top();
        stk.erase(it);
        valToIters[maxVal].pop();

        if (valToIters[maxVal].size() == 0) {
            valToIters.erase(maxVal);
        }

        return maxVal;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */