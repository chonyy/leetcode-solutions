class StockSpanner {
public:
    vector<pair<int,int>> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (prices.empty()) {
            prices.push_back({price, 1});
            return 1;
        }

        int idx = prices.size() - 1;
        int combo = 1;
        while (idx >= 0 && prices[idx].first <= price) {
            // cout << price << " " << prices[idx].first << endl;
            // cout << "move " << prices[idx].second << endl;
            combo += prices[idx].second;
            idx -= prices[idx].second;
        }
        
        prices.push_back({price, combo});
        // cout << "push " << price << " " << combo << endl;

        return combo;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */