class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        for(int i = 0; i <= k; i ++) {
            vector<int> temp = dist;
            for(auto& f : flights) {
                if(dist[f[0]] != INT_MAX && dist[f[0]] + f[2] < temp[f[1]]) {
                    temp[f[1]] = dist[f[0]] + f[2];
                }
            }
            swap(temp, dist);
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};