class HitCounter {
public:
    int limit = 300;
    queue<int> timestamps;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        while (!timestamps.empty() && timestamps.front() <=  timestamp - limit) {
            timestamps.pop();
        }
        timestamps.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while (!timestamps.empty() && timestamps.front() <=  timestamp - limit) {
            timestamps.pop();
        }
        return timestamps.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */