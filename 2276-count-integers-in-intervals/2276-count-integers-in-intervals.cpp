class CountIntervals {
public:
    map<int,int> intervals;
    int cnt = 0;

    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it = intervals.upper_bound(left);

        if (it != intervals.begin() && prev(it)->second >= left) {
            it --;
        }

        int newLeft = left;
        int newRight = right;
        
        while (it != intervals.end() && it->first <= right) {
            newLeft = min(newLeft, it->first);
            newRight = max(newRight, it->second);
            cnt -= it->second - it->first + 1;
            it = intervals.erase(it);
        }

        intervals[newLeft] = newRight;
        cnt += newRight - newLeft + 1;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */