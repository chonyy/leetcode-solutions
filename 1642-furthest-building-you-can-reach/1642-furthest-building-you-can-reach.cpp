class Solution {
public:
    int furthestBuilding(vector<int>& A, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i < A.size(); i++) {
            int d = A[i] - A[i-1];
            if (d > 0)
                pq.push(d);
            if (pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }
            if (bricks < 0)
                return i-1;
        }
        return A.size() - 1;
    }
};