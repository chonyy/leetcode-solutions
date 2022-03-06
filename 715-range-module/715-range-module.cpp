class RangeModule {
public:
    map<int,int> ranges;
    
    RangeModule() {
        
    }
    
    pair<map<int,int> :: iterator, map<int,int> :: iterator> getOverlapRange(int left, int right) {
        auto l = ranges.upper_bound(left);
        auto r = ranges.upper_bound(right);
        if(l != ranges.begin()) {
            l = prev(l);
            if(l->second < left)
                l = next(l);
        }
        
        return {l, r};
    }
    
    void addRange(int left, int right) {
        auto ran = getOverlapRange(left, right);
        // cout << "get range" << endl;
        auto l = ran.first;
        auto r = ran.second;
        
        if(l != r) { // at least one overlap
            auto last = prev(r);
            // update left and right
            left = min(left, l->first);
            right = max(right, last->second);
            
            // remove overlapped
            ranges.erase(l, r);
        }
        
        ranges[left] = right;
        // cout << "finish add" << endl;
    }
    
    bool queryRange(int left, int right) {
        auto ran = getOverlapRange(left, right);
        auto l = ran.first;
        auto r = ran.second;
        
        if(l == r)
            return false;
        return l->first <= left && right <= l->second;
    }
    
    void removeRange(int left, int right) {
        auto ran = getOverlapRange(left, right);
        auto l = ran.first;
        auto r = ran.second;
        
        if(l == r)
            return;
        
        auto last = prev(r);
        int start = min(l->first, left);
        int end = max(last->second, right);
        
        // delete
        ranges.erase(l, r);
        
        if(start < left)
            ranges[start] = left;
        if(end > right)
            ranges[right] = end;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */