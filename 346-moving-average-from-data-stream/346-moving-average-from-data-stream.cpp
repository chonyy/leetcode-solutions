class MovingAverage {
public:
    int windowSize = 0;
    int curSum = 0;
    deque<int> deq;
    
    MovingAverage(int size) {
        windowSize = size;
    }
    
    double next(int val) {
        if(deq.size() == windowSize) {
            curSum -= deq.front();
            deq.pop_front();
        }
        
        curSum += val;
        deq.push_back(val);
        
        return (double)curSum / deq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */