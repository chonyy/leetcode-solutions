class TimeMap {
    unordered_map<string, map<int, string>> m;
public:
    /** Initialize your data structure here. */
    TimeMap() {
    }
    
    // insert into a map is O(logN)
    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }
    
    // Perform binary search, O(logN)
    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */