class Solution {
public:
    vector<string> getNeighbors(string s) {
        vector<string> neighbors;

        for(int i = 0; i < 4; i ++) {
            char digit = s[i];
            string s1 = s.substr(0, i) + (digit == '9' ? '0' : char(digit + 1)) + s.substr(i+1); 
            string s2 = s.substr(0, i) + (digit == '0' ? '9' : char(digit - 1)) + s.substr(i+1); 
            neighbors.push_back(s1);
            neighbors.push_back(s2);
        }

        return neighbors;
    } 
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> ends(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        
        if(ends.find("0000") != ends.end())
            return -1;
        
        if(target == "0000")
            return 0;
        
        q.push("0000");
        visited.insert("0000");
        int turn = 0;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i ++) {
                auto cur = q.front();
                q.pop();

                if(cur == target)
                    return turn;

                auto neighbors = getNeighbors(cur);
                for(auto& nei : neighbors) {
                    if(visited.find(nei) != visited.end()) {
                        continue;
                    }            
                    if(ends.find(nei) != ends.end()) {
                        continue;
                    }

                    visited.insert(nei);
                    q.push(nei);
                }
            }
            turn ++;
        }
        
        return -1;
    }
};