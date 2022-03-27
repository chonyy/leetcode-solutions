class ExamRoom {
public:
    int size;
    set<int> s;
    ExamRoom(int n) {
        size = n-1;
    }
    
    int seat() {
        if(s.size() == 0) {
            s.insert(0);
            return 0;
        }
        
        int maxDist = *s.begin() - 0;
        int ans = 0;
        for(auto it = next(s.begin()); it != s.end(); it ++) {
            int curPos = *it;
            int prevPos = *(prev(it));
            int dist = (curPos - prevPos) / 2;
            if(dist > maxDist) {
                maxDist = dist;
                ans = prevPos + dist;
            }
        }
        
        // check last
        if(size - *s.rbegin() > maxDist) {
            ans = size;
        }
        
        s.insert(ans);
        return ans;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */