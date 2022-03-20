class UnionFind {
    public:
        unordered_map<int,int> parent;
        int size;
    
        int find(int node) {
            if(parent[node] != node) {
                return parent[node] = find(parent[node]);
            } 
            return node;
        }
    
        void unionn(int u, int v) {
            // init
            if(parent.count(u) == 0)
                parent[u] = u;
            if(parent.count(v) == 0)
                parent[v] = v;
            
            int pu = find(u);
            int pv = find(v);
            
            if(pu != pv) {
                parent[pu] = pv;
            }
        }
    
        unordered_map<int, vector<int>> getGroup() {
            unordered_map<int, vector<int>> group;
            
            for(auto& entry : parent) {
                group[find(entry.second)].push_back(entry.first);
            }
            
            return group;
        }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        unordered_map<int, int> rank;
        map<int, vector<pair<int,int>>> valueGroup;
        
        // group same value together
        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                int val = matrix[i][j];
                valueGroup[val].push_back({i, j});
            }
        }
        
        // process group by group
        for(auto& group : valueGroup) {
            auto uf = UnionFind();
            int val = group.first;
            // cout << "val " << val << endl;
            auto& cells = group.second;
            
            // union the cells
            for(auto& c : cells) {
                // cout << c.first << " " << c.second << endl;
                uf.unionn(c.first, rows+c.second);
            }
            
            // update row col rank
            auto nodeGroup = uf.getGroup();
            for(auto& entry : nodeGroup) {
                auto& nodes = entry.second;
                int maxRank = 0;
                
                // cout << "rank" << endl;
                for(int node : nodes) {
                    // cout << node << " " << rank[node] << endl;
                    maxRank = max(maxRank, rank[node]);
                }
                for(int node : nodes) {
                    rank[node] = maxRank + 1;
                }
            }       
            
            // update cell rank
            for(auto& c : cells) {
                matrix[c.first][c.second] = rank[c.first];
            }
            // cout << endl;
        }
        
        return matrix;
    }
};