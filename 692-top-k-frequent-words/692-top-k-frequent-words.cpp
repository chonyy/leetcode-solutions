class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> frequency;
        
        for(string& word : words) {
            frequency[word] ++;
        }
        
        auto cmp = [](auto& p1, auto& p2) {
            if(p1.first == p2.first) {
                return p1.second > p2.second; 
            }
            return p1.first < p2.first;
        };
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(cmp)> pq(cmp);
        
        for(auto entry : frequency) {
            pq.push({entry.second, entry.first});
        }
        
        vector<string> res;
        for(int i = 0; i < k; i ++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};