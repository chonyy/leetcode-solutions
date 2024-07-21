class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalSort(k + 1, rowConditions);
        vector<int> colOrder = topologicalSort(k + 1,colConditions);

        if(rowOrder.size() == 0) {
            return {};
        }
        if(colOrder.size() == 0) {
            return {};
        }

        unordered_map<int,int> rowValToIdx = toMap(rowOrder);
        unordered_map<int,int> colValToIdx = toMap(colOrder);

        vector<vector<int>> res(k, vector<int>(k));

        for(int i = 1; i < k+1; i ++) {
            int r = rowValToIdx[i];
            int c = colValToIdx[i];

            res[r][c] = i;
        }

        return res;
    }

    unordered_map<int, int> toMap(vector<int>& array) {
        unordered_map<int, int> m;

        for(int i = 0; i < array.size(); i ++) {
            m[array[i]] = i;
        }

        return m;
    }

    vector<int> topologicalSort(int size, vector<vector<int>>& edges) {
        vector<vector<int>> graph(size);
        vector<int> inDegree(size);
        
        for(auto& pre : edges) {
            graph[pre[0]].push_back(pre[1]);
            inDegree[pre[1]] ++;
        }
        
        queue<int> q;
        int count = 0;
        
        for(int i = 1; i < size; i ++) {
            if(inDegree[i] == 0) {
                q.push(i);
                count ++;
            }
        }
        
        vector<int> res;
        
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            res.push_back(cur);
            
            auto& neighbors = graph[cur];
            for(auto nei : neighbors) {
                inDegree[nei] --;
                if(inDegree[nei] == 0) {
                    q.push(nei);
                    count ++;
                }
            }
        }

        cout << count << endl;
        
        return count == size-1 ? res : vector<int>{};
    }

    void printArr(vector<int>& arr) {
        for(auto num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};