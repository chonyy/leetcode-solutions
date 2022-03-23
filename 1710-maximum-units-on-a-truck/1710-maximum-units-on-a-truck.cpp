class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        
        for(auto& type : boxTypes) {
            int num = type[0];
            int weight = type[1];
            
            for(int i = 0; i < num; i ++) {
                pq.push(weight);
                sum += weight;
                
                if(pq.size() > truckSize) {
                    sum -= pq.top();
                    pq.pop();
                }
            }
        }
        
        return sum;
    }
};