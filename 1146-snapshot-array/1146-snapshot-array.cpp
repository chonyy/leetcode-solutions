class SnapshotArray {
public:
    vector<map<int,int>> log;
    int snaps = 0;

    SnapshotArray(int length) {
        log = vector<map<int,int>>(length);
    }
    
    void set(int index, int val) {
        log[index][snaps] = val;
    }
    
    int snap() {
        return snaps ++;
    }
    
    int get(int index, int snap_id) {
        auto nextLarge = log[index].upper_bound(snap_id);

        if (nextLarge == log[index].begin()) {
            return 0;
        }

        nextLarge --;
        return nextLarge->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */