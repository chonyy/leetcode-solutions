class Solution {
public:
    int distance(vector<int>& point) {
        int x = point[0];
        int y = point[1];
        return x*x + y*y;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](pair<int, vector<int>> &p1, pair<int, vector<int>> &p2){
            return p1.first > p2.first;
        };
        
        
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(cmp)> pq(cmp);
        vector<vector<int>> res;
        
        for(auto& point : points) {
            pq.push({distance(point), point});
        }
        
        while(k --) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};