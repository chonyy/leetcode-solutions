class StockPrice {
public:
    map<int,int> timePrice;
    multiset<int> prices;
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(timePrice.count(timestamp)) {
            int oldPrice = timePrice[timestamp];
            auto it = prices.find(oldPrice);
            prices.erase(it);
        }
        
        timePrice[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return timePrice.rbegin()->second;
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */