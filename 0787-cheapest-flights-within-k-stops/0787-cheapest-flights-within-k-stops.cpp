class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // bellman ford
        // loop k+1 times, for each loop
        // if not inf, check if src to dst can ahieve lower cose

        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i = 0; i < k+1; i ++) {
            vector<int> temp = prices;
            for (auto& flight : flights) {
                int cur = flight[0];
                int next = flight[1];
                int cost = flight[2];

                // cout << "k " << i << endl;

                if (prices[cur] == INT_MAX) {
                    continue;
                }

                if (prices[cur] + cost < temp[next]) {
                    // cout << next << " " << prices[cur] + cost << endl;
                    temp[next] = prices[cur] + cost;
                }
            }
            swap(temp, prices);
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};