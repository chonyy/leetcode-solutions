class RangeModule {
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        IT l, r;
        getOverlapRanges(left, right, l, r);
        // At least one range overlapping with [left, right)
        if (l != r) {
            // Merge intervals into [left, right)
            auto last = r; --last;
            left = min(left, l->first);            
            right = max(right, last->second);
            // Remove all overlapped ranges
            ranges_.erase(l, r);
        }
        // Add a new/merged range
        ranges_[left] = right;
    }
    
    bool queryRange(int left, int right) {
        IT l, r;
        getOverlapRanges(left, right, l, r);
        // No overlapping range
        if (l == r) return false;
        return l->first <= left && l->second >= right;
    }
    
    void removeRange(int left, int right) {
        IT l, r;
        getOverlapRanges(left, right, l, r);
        // No overlapping range
        if (l == r) return;
        auto last = r; --last;
        int start = min(left, l->first);        
        int end = max(right, last->second);
        // Delete overlapping ranges        
        ranges_.erase(l, r);
        if (start < left) ranges_[start] = left;
        if (end > right) ranges_[right] = end;
    }
private:
    typedef map<int, int>::iterator IT;
    map<int, int> ranges_;
    void getOverlapRanges(int left, int right, IT& l, IT& r) {
        l = ranges_.upper_bound(left);
        r = ranges_.upper_bound(right);
        if (l != ranges_.begin())
            if ((--l)->second < left) l++;
    }
};