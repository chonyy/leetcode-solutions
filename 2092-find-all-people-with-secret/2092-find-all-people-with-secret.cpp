class UnionFind {
    public:
        unordered_map<int,int> parent;
        int size;

        UnionFind(int n, int first) {
            for(int i = 0; i < n; i ++) {
                parent[i] = i;
            }
            parent[first] = 0;
            size = n;
        }
    
        int find(int node) {
            if(parent[node] != node) {
                return parent[node] = find(parent[node]);
            } 
            return node;
        }
    
        void unionn(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            
            if(pu != pv) {
                parent[pu] = pv;
            }
        }
    
        void reset(int node) {
            parent[node] = node;
        }
    
        bool connected(int u, int v) {
            return find(u) == find(v);
        }
    
        vector<int> getGroup(int node) {
            vector<int> res; 
            
            for(int i = 0; i < size; i ++ ){
                if(connected(i, node)) {
                    res.push_back(i);
                }
            }
            
            return res;
        }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        auto cmp = [](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };
        sort(meetings.begin(), meetings.end(), cmp);
        auto uf = UnionFind(n, firstPerson);
        int m = meetings.size();
        vector<int> pool;
        
        for(int i = 0; i < m; i ++) {
            auto& meet = meetings[i];
            if(i > 0 && meet[2] != meetings[i-1][2]) {
                for(int p : pool) {
                    if(!uf.connected(0, p)) {
                        // cout << "reset " << j << endl;
                        uf.reset(p);
                    } 
                }
                pool.clear();
            }
            
            uf.unionn(meet[0], meet[1]);
            pool.push_back(meet[0]);
            pool.push_back(meet[1]);
        }
        
        return uf.getGroup(0);
    }
};



