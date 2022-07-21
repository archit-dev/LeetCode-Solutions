class StockPrice {
public:
    map<int,int>store;
    multiset<int>count;
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if(store.find(timestamp)!=store.end()){
            count.erase(count.find(store[timestamp]));
        }
        store[timestamp] = price;
        count.insert(price);
    }
    
    int current() {
        return store.rbegin()->second;
    }
    
    int maximum() {
        return *count.rbegin();
    }
    
    int minimum() {
        return *count.begin();
    }
};
