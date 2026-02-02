class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> store;
public:

    // key: {timestamp, value}, {timestamp, value}
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!store.contains(key)) {
            return "";
        }

        vector<pair<int,string>>& values = store[key];
        int l = 0;
        int r = values.size();

        while (l < r) {
            int mid = l + (r - l) / 2;
            int time = values[mid].first;
            string val = values[mid].second;

            if (time == timestamp) {
                return val;
            }

            if (time > timestamp) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        // cout << l << endl;

        return l == 0 ? "" : values[l - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

//  1 3 4 5
//  l     r
