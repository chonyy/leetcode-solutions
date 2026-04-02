class Solution {
public:
    unordered_map<string,int> mem;

    int maxProfit(vector<int>& prices) {
        return dfs(prices, 0, true);
    }

    int dfs(vector<int>& prices, int idx, bool canBuy) {
        if (idx >= prices.size()) {
            return 0;
        }

        string key = to_string(idx) + "#" + to_string(canBuy);
        if (mem.contains(key)) {
            return mem[key];
        }

        if (canBuy) {
            // buy
            int buy = dfs(prices, idx+1, false) - prices[idx];

            // not buy
            int notBuy = dfs(prices, idx+1, true);

            mem[key] = max(buy, notBuy);
            return max(buy, notBuy);
        }


        // sell
        int sell = dfs(prices, idx+2, true) + prices[idx];

        // not sell
        int notSell = dfs(prices, idx+1, false);

        mem[key] = max(sell, notSell);
        return max(sell, notSell);
    }
};

// buy

// sell

// cooldown

// buy = max(buy, cooldown - prices[i])

// sell = buy + prices[i]

// cooldown = max(cooldown, sell)

// canBuy 

// if canBuy
//     buy
//         profit -= price
//         i+1

//     don't buy
//         profit = profit
//         i+1

// if canBuy == false
//     sell
//         profit += price
//         i+2

//     don't sell
//         profit = profit
//         i+1

