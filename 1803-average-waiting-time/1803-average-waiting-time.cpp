class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double sum = 0;
        int cur = 0;

        for(auto& customer : customers) {
            int extra = max(0, cur - customer[0]);
            int wait = customer[1] + extra;

            sum += wait;
            cur = max(cur, customer[0] + wait);
        }

        return sum / n;
    }
};