class Solution {
public:
    int mod = 1e9 + 7;

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        map<int, int, greater<>> buy; // highest first
        map<int, int> sell;           // lowest first

        for (auto& o : orders) {
            int price = o[0], amount = o[1];

            if (o[2] == 0) { // buy — match against cheapest sells
                while (amount > 0 && !sell.empty() && sell.begin()->first <= price) {
                    auto it = sell.begin();
                    int toConsume = min(it->second, amount);
                    it->second -= toConsume;
                    amount -= toConsume;
                    if (it->second == 0) sell.erase(it);
                }
                if (amount) buy[price] += amount;
            } else { // sell — match against highest buys
                while (amount > 0 && !buy.empty() && buy.begin()->first >= price) {
                    auto it = buy.begin();
                    int toConsume = min(it->second, amount);
                    it->second -= toConsume;
                    amount -= toConsume;
                    if (it->second == 0) buy.erase(it);
                }
                if (amount) sell[price] += amount;
            }
        }

        long long res = 0;
        for (auto& [_, amt] : buy) res += amt;
        for (auto& [_, amt] : sell) res += amt;
        return res % mod;
    }
};