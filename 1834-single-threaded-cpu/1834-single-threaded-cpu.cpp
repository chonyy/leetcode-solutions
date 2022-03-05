class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // add orig index
        int n = tasks.size();
        
        for(int i = 0 ; i < n ; i ++) {
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin(), tasks.end());
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> res;
        int largestTime = tasks[n-1][0];
        int curTask = 0;
        long long time = 0;
        
        while(!pq.empty() || curTask < n) {
            // add new task
            while(curTask < n && tasks[curTask][0] <= time) {
                pq.push({tasks[curTask][1], tasks[curTask][2]});
                // cout << time << " push " << tasks[curTask][2] << endl;
                curTask ++;
            }
            
            // nothing to pop, fast forward
            if(pq.empty()) {
                time = tasks[curTask][0];
            }
            
            // pop from queue
            if(!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                res.push_back(cur.second);
                time += cur.first;
            }
        }
        
        return res;
    }
};