class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a > 0)
            pq.push({a, 'a'});
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});
        
        string res = "";
        char comboChar = '#';
        int combo = 1;
        
        while(!pq.empty()) {
            // get most frequent
            auto cur = pq.top();
            pq.pop();
            
            // check for combo
            if(combo == 2 && comboChar == cur.second) {
                // get the second frequent
                // break if not enough
                if(pq.empty())
                    break;
                
                auto second = pq.top();
                pq.pop();
                res += second.second;
                if(second.first-1 > 0) {
                    pq.push({second.first-1, second.second});
                }

                comboChar = second.second;
                combo = 1;
                
                // push original
                pq.push(cur);
            }
            else {
                // update combo
                if(cur.second == comboChar)
                    combo ++;
                else {
                    comboChar = cur.second;
                    combo = 1;
                } 
                
                // update res
                // push back to pq
                res += cur.second;
                if(cur.first - 1 > 0)
                    pq.push({cur.first - 1, cur.second});
            }
        }
        
        return res;
    }
};