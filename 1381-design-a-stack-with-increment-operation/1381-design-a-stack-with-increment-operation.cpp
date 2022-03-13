class CustomStack {
public:
    vector<int> stk;
    vector<int> inc;
    int size;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(stk.size() == size) {
            return;
        }
        
        stk.push_back(x);
        inc.push_back(0);
    }
    
    int pop() {
        if(stk.size() == 0) {
            return -1;
        }
        
        int n = stk.size() - 1;
        int val = stk[n];
        int increase = inc[n];
        if(n > 0)
            inc[n-1] += increase;
        
        inc.pop_back();
        stk.pop_back();
        
        return val + increase;
    }
    
    void increment(int k, int val) {
        int last = stk.size() - 1;
        k = min(k-1, last);
        if(k >= 0)
            inc[k] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */