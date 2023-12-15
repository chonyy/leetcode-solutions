class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> hasOutgoing;
        for (int i = 0; i < paths.size(); i++) {
            hasOutgoing.insert(paths[i][0]);
        }
        
        for (int i = 0; i < paths.size(); i++) {
            string candidate = paths[i][1];
            if (hasOutgoing.find(candidate) == hasOutgoing.end()) {
                return candidate;
            }
        }
        
        return "";
    }
};