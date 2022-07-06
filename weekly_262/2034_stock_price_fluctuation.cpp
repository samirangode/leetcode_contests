#include <bits/stdc++.h>

using namespace std;

class StockPrice {
private:
    pair<int, int> min;
    pair<int, int> max;
    map<int,int> m;

public:
    StockPrice() {
        min = {-1,INT_MAX};
        max = {-1,INT_MIN};
    }
    
    void update(int timestamp, int price) {
        if(m.find(timestamp)!=m.end()){
            m[timestamp] = price;
            if(min.first==timestamp)
        }
        else{
            m.insert({timestamp,price});
        }
        if(price<min){
            min = price;
        }
        if(price>max){
            max = price;
        }
    }
    
    int current() {
        auto it = m.end();
        it--;
        return it->second;
    }
    
    int maximum() {
        return max;
    }
    
    int minimum() {
        return min;
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
