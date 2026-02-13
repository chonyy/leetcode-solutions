class SnapshotArray {
    unordered_map<int, map<int, int>> m;
    int snaps = 0;
public:
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        m[index][snaps] = val;
    }
    
    int snap() {
        return snaps ++;
    }
    
    int get(int index, int snap_id) {
        auto it = m[index].upper_bound(snap_id);
        return it == m[index].begin() ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */