class Solution {
public:
    long long hash(int y1, int y2) {
        return (long long)y1 ^ (long long)y2 << 32;
    }
    
    int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> count;
        
        for(auto& p : points) {
            count[p[0]].push_back(p[1]);
        }
        
        int minArea = INT_MAX;
        unordered_map<long long, int> seen;
        
        for(auto& entry : count) {
            int x = entry.first;
            auto& ys = entry.second;
            for(auto y1 : ys) {
                for(auto y2 : ys) {
                    if(y1 == y2)
                        continue;
                    
                    long long key = hash(y1, y2);
                    if(seen.find(key) != seen.end()) {
                        int area = (x - seen[key]) * abs(y1 - y2);
                        minArea = min(minArea, area);
                    }
                    
                    seen[key] = x;
                }
            }
        }
        
        return minArea == INT_MAX ? 0 : minArea;
    }
};