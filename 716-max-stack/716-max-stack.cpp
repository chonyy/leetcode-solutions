class MaxStack {
public:
    list<int> stk;
    map<int, stack<list<int> :: iterator>> stkMap;
    MaxStack() {
        
    }
    
    void push(int x) {
        stk.push_front(x);
        stkMap[x].push(stk.begin());
    }
    
    int pop() {
        int val = stk.front();
        
        // pop from stkMap
        stkMap[val].pop();
        if(stkMap[val].empty())
            stkMap.erase(val);
        stk.pop_front();
        
        return val;
    }
    
    int top() {
        return stk.front();
    }
    
    int peekMax() {
        return stkMap.rbegin()->first;
    }
    
    int popMax() {
        int maxVal = peekMax();
        auto it = stkMap[maxVal].top();
        
        // remove from map
        stkMap[maxVal].pop();
        if(stkMap[maxVal].empty())
            stkMap.erase(maxVal);
        
        stk.erase(it);
        
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